// Svm_classify.cpp: implementation of the CSvm_classify class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "svm.h"
#include "svm_common.h"
#include "Svm_classify.h"


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


//char predictionsfile[200];
static char temstr[200];

int svm_classify ()
{
	DOC doc;   /* test example */
	long max_docs,max_words_doc,lld,llsv;
	long max_sv,max_words_sv,totdoc=0,doc_label;
	long correct=0,incorrect=0,no_accuracy=0;
	long res_a=0,res_b=0,res_c=0,res_d=0,wnum,pred_format;
	long j;
	double t1,runtime=0;
	double dist;
	char *line; 
	FILE *predfl,*docfl;
	MODEL model; 
	char docfile[200];
	char modelfile[200];
	char predictionsfile[200];
	
	strcpy(docfile,com_param.classifyfile);
	strcpy(modelfile,com_param.modelfile);
	strcpy(predictionsfile,com_param.resultfile);
	pred_format=0;
	
	nol_ll(docfile,&max_docs,&max_words_doc,&lld); /* scan size of input file */
	max_words_doc+=2;
	lld+=2;
	nol_ll(modelfile,&max_sv,&max_words_sv,&llsv); /* scan size of model file */
	max_words_sv+=2;
	llsv+=2;
	model.supvec = (DOC **)my_malloc(sizeof(DOC *)*max_sv);
	model.alpha = (double *)my_malloc(sizeof(double)*max_sv);
	line = (char *)my_malloc(sizeof(char)*lld);
	doc.words = (SVM_WORD *)my_malloc(sizeof(SVM_WORD)*(max_words_doc+10));
	read_model(modelfile,&model,max_words_sv,llsv);
	/* linear kernel */
		/* compute weight vector */
	if(model.kernel_parm.kernel_type == 0)
	{ 
		add_weight_vector_to_linear_model(&model);
	}
	if (com_pro.show_action)
		printm("Classifying test examples..");

	if ((docfl = fopen (docfile, "r")) == NULL)
	{
		printe (docfile);
		return -1;
	}
	if ((predfl = fopen (predictionsfile, "w")) == NULL)
	{
		printe (predictionsfile); 
		return -1;
	}
//chen 10.9.2001
	int clb_number=0;
	while((!feof(docfl)) && fgets(line,(int)lld,docfl)) 
	{
		if(line[0] == '#') continue;  /* line contains comments */
		parse_document(line,&doc,&doc_label,&wnum,max_words_doc);
		totdoc++;
		clb_number++;
		if(model.kernel_parm.kernel_type == 0) 
		{   /* linear kernel */
			for(j=0;(doc.words[j]).wnum != 0;j++) 
			{  /* Check if feature numbers are not larger than in    
				 model. Remove feature if necessary.  */
				if((doc.words[j]).wnum>model.totwords) 
					(doc.words[j]).wnum=0;              
			}                                        
			t1=get_runtime();
			dist=classify_example_linear(&model,&doc);
			runtime+=(get_runtime()-t1);
		}
		else /* non-linear kernel */
		{                            
			t1=get_runtime();
			dist=classify_example(&model,&doc);
			runtime+=(get_runtime()-t1);
		}
		if(dist>0)
		{
			if(pred_format==0) 
			{ /* old weired output format */
				fprintf(predfl,"%d\t%8.5g\t+1",clb_number,dist );
			}
			if(doc_label==1) 
				fprintf(predfl," CORRECT \n");
			else fprintf(predfl," \n");
			if(doc_label==1) correct++; else incorrect++;
			if(doc_label==1) res_a++; else res_b++;
		}
		else 
		{
			if(pred_format==0)
			{ /* old weired output format */
				fprintf(predfl,"%d\t%8.5g:\t-1",clb_number,dist);
			}
			if(doc_label==-1) 
				fprintf(predfl," CORRECT \n");
			else fprintf(predfl," \n");
			
			if(doc_label==-1) correct++; else incorrect++;
			if(doc_label==1) res_c++; else res_d++;
		}
		if(pred_format==1) 
		{ /* output the value of decision function */
			fprintf(predfl,"%5.8g\n",dist);
		}
		if((doc_label*doc_label) != 1) 
			no_accuracy=1; 
		
		if((totdoc % 20 == 0) &&(com_pro.show_readfile))
		{
			sprintf(temstr,"%ld..",totdoc); 
			printm(temstr);
		}
	}  
	free(line);
	free(doc.words);
	free(model.supvec);
	free(model.alpha);
	if(model.kernel_parm.kernel_type == 0) 
	{ /* linear kernel */
		free(model.lin_weights);
	}
	
	
	/*   Note by Gary Boone                     Date: 29 April 2000        */
	/*      o Timing is inaccurate. The timer has 0.01 second resolution.  */
	/*        Because classification of a single vector takes less than    */
	/*        0.01 secs, the timer was underflowing.                       */
	if (com_pro.show_other)
	{
    sprintf(temstr,"Runtime (without IO) in cpu-seconds: %.2f\n",
		(float)(runtime/100.0));
	printm(temstr);
	}
    
	if((!no_accuracy)&&com_pro.show_testresult )
	{
//		sprintf(temstr,"Accuracy on test set: %.2f%% (%ld correct, %ld incorrect, %ld total)",(float)(correct)*100.0/totdoc,correct,incorrect,totdoc);
				sprintf(temstr,"%.2f%% ",(float)(correct)*100.0/totdoc);
		printm(temstr);
		//temp
		if (com_pro.show_other)
		{
		sprintf(temstr,"Precision/recall on test set: %.2f%%/%.2f%%\n",(float)(res_a)*100.0/(res_a+res_b),(float)(res_a)*100.0/(res_a+res_c));
		printm(temstr);
		}
	}
	fclose(predfl);
	return(0);
}

