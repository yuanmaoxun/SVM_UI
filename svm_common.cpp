#include "stdafx.h"
#include "svm.h"
#include "svm_common.h"
#include "math.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif




static char temstr[200];
/* classifies example */
double classify_example(MODEL *model,DOC *ex)
{
	register long i;
	register double dist;
	
	dist=0;
	for(i=1;i<model->sv_num;i++) {  
		dist+=kernel(&model->kernel_parm,model->supvec[i],ex)*model->alpha[i];
	}
	return(dist-model->b);
}

/*    classifies example for linear kernel 
important: the model must have the linear weight vector computed 
important: the feature numbers in the example to classify must 
not be larger than the weight vector!               */
double classify_example_linear(MODEL *model,DOC *ex)
{
	return((double)(sprod_ns(model->lin_weights,ex->words)-model->b));
}

/* calculate the kernel function */
CFLOAT kernel(KERNEL_PARM *kernel_parm,DOC *a,DOC*b)
{
	com_result.kernel_cache_statistic++;
	switch(kernel_parm->kernel_type)
	{
    case 0: /* linear */ 
		return((CFLOAT)sprod_ss(a->words,b->words)); 
    case 1: /* polynomial */
		return((CFLOAT)pow(kernel_parm->coef_lin*sprod_ss(a->words,b->words)+kernel_parm->coef_const,(double)kernel_parm->poly_degree)); 
    case 2: /* radial basis function */
		return((CFLOAT)exp(-kernel_parm->rbf_gamma*(a->twonorm_sq-2*sprod_ss(a->words,b->words)+b->twonorm_sq)));
    case 3: /* sigmoid neural net */
		return((CFLOAT)tanh(kernel_parm->coef_lin*sprod_ss(a->words,b->words)+kernel_parm->coef_const)); 
    case 4: /* custom-kernel supplied in file kernel.h*/
		return((CFLOAT)custom_kernel(kernel_parm,a,b)); 
		//chen .test sum of 
		//return((CFLOAT)pow(kernel_parm->coef_lin*sprod_ss(a->words,b->words)+kernel_parm->coef_const,(double)kernel_parm->poly_degree)+exp(-kernel_parm->rbf_gamma*(a->twonorm_sq-2*sprod_ss(a->words,b->words)+b->twonorm_sq))); 
    default: sprintf(temstr,"Error: Unknown kernel function");
		printm(temstr);
		return (-1);
	}
}

/* compute the inner product of two sparse vectors */
double sprod_ss(SVM_WORD *a,SVM_WORD*b)
{
    register FVAL sum=0;
    register SVM_WORD *ai,*bj;
    ai=a;
    bj=b;
    while (ai->wnum && bj->wnum) {
		if(ai->wnum > bj->wnum) {
			bj++;
		}
		else if (ai->wnum < bj->wnum) {
			ai++;
		}
		else {
			sum+=ai->weight * bj->weight;
			ai++;
			bj++;
		}
    }
    return((double)sum);
}



/* compute the inner product of two sparse vectors,b right shit 1 bit */
double sprod_ss1(SVM_WORD *a,SVM_WORD*b,int offset)
{
    register FVAL sum=0;
    register SVM_WORD *ai,*bj;
    ai=a;
    bj=b;
    while (ai->wnum && bj->wnum) {
		if(ai->wnum > bj->wnum+offset) {
			bj++;
		}
		else if (ai->wnum < bj->wnum+offset) {
			ai++;
		}
		else 
		{
			int np=(ai->wnum-1)%16+1+offset;
			if (np>0 && np<17) 
				sum+=ai->weight * bj->weight;
			ai++;
			bj++;
		}
    }
    return((double)sum);
}

double sprod_ss2(SVM_WORD *a,SVM_WORD*b,int offset)
{
    register FVAL sum=0;
    register SVM_WORD *ai,*bj;
    ai=a;
    bj=b;
    while (ai->wnum && bj->wnum) {
		if(ai->wnum > bj->wnum+offset) {
			bj++;
		}
		else if (ai->wnum < bj->wnum+offset) {
			ai++;
		}
		else 
		{
			int np=ai->wnum+offset;
			if (np>0 && np<257) 
				sum+=ai->weight * bj->weight;
			ai++;
			bj++;
		}
    }
    return((double)sum);
}

/* compute length of weight vector */
double model_length_s(MODEL *model,KERNEL_PARM *kernel_parm)
{
	register long i,j;
	register double sum=0,alphai;
	register DOC *supveci;
	
	for(i=1;i<model->sv_num;i++) {  
		alphai=model->alpha[i];
		supveci=model->supvec[i];
		for(j=1;j<model->sv_num;j++) {
			sum+=alphai*model->alpha[j]
				*kernel(kernel_parm,supveci,model->supvec[j]);
		}
	}
	return(sqrt(sum));
}

void clear_vector_n(double *vec,long n)
{
	register long i;
	for(i=0;i<=n;i++) vec[i]=0;
}

void add_vector_ns(double *vec_n,SVM_WORD *vec_s,double faktor)
{
	register SVM_WORD *ai;
	ai=vec_s;
	while (ai->wnum) {
		vec_n[ai->wnum]+=(faktor*ai->weight);
		ai++;
	}
}

double sprod_ns(double *vec_n,SVM_WORD *vec_s)
{
	register double sum=0;
	register SVM_WORD *ai;
	ai=vec_s;
	while (ai->wnum) {
		sum+=(vec_n[ai->wnum]*ai->weight);
		ai++;
	}
	return(sum);
}

/* compute weight vector in linear case and add to model*/
void add_weight_vector_to_linear_model(MODEL *model)
{
	long i;
	
	model->lin_weights=(double *)my_malloc(sizeof(double)*(model->totwords+1));
	clear_vector_n(model->lin_weights,model->totwords);
	for(i=1;i<model->sv_num;i++) {
		add_vector_ns(model->lin_weights,(model->supvec[i])->words,
			model->alpha[i]);
	}
}

int read_model(char *modelfile,MODEL *model,long max_words,long ll)
{
	FILE *modelfl;
	long j,i;
	char *line;
	SVM_WORD *words;
	register long wpos;
	long wnum,pos;
	double weight;
	char version_buffer[100];

	if (com_pro.show_action)
	{
	
		sprintf(temstr,"Reading model..."); 
		printm(temstr); 
	}
	
	words = (SVM_WORD *)my_malloc(sizeof(SVM_WORD)*(max_words+10));
	line = (char *)my_malloc(sizeof(char)*ll);
	
	if ((modelfl = fopen (modelfile, "r")) == NULL)
	{
		printe (modelfile);  
		return -1;
	}
	
	fscanf(modelfl,"SVM-light Version %s\n",version_buffer);
	
	if(strcmp(version_buffer,VERSION)) 
	{
		printe ("Version of model-file does not match version of svm_classify!"); 
		return -1;
	}

	
	fscanf(modelfl,"%ld # kernel type\n",&(model->kernel_parm.kernel_type));
	fscanf(modelfl,"%ld # kernel parameter -d \n",&(model->kernel_parm.poly_degree));
	fscanf(modelfl,"%lf # kernel parameter -g \n",&(model->kernel_parm.rbf_gamma));
	fscanf(modelfl,"%lf # kernel parameter -s \n",&(model->kernel_parm.coef_lin));
	fscanf(modelfl,"%lf # kernel parameter -r \n",&(model->kernel_parm.coef_const));
	fscanf(modelfl,"%s # kernel parameter -u \n",&(model->kernel_parm.custom));
	fscanf(modelfl,"%ld # highest feature index \n",&(model->totwords));
	fscanf(modelfl,"%ld # number of training documents \n",&(model->totdoc));
	fscanf(modelfl,"%ld # number of support vectors plus 1 \n",&(model->sv_num));
	fscanf(modelfl,"%lf # threshold b \n",&(model->b));
	
	for(i=1;i<model->sv_num;i++) 
	{
		fgets(line,(int)ll,modelfl);
		pos=0;
		wpos=0;
		sscanf(line,"%lf",&model->alpha[i]);
		while(line[++pos]>' ');
		while((sscanf(line+pos,"%ld:%lf",&wnum,&weight) != EOF) && (wpos<max_words)) 
		{
			while(line[++pos]>' ');
			words[wpos].wnum=wnum;
			words[wpos].weight=weight; 
			wpos++;
		} 
		model->supvec[i] = (DOC *)my_malloc(sizeof(DOC));
		(model->supvec[i])->words = (SVM_WORD *)my_malloc(sizeof(SVM_WORD)*(wpos+1));
		for(j=0;j<wpos;j++)
		{
			(model->supvec[i])->words[j]=words[j]; 
		}
		((model->supvec[i])->words[wpos]).wnum=0;
		(model->supvec[i])->twonorm_sq = sprod_ss((model->supvec[i])->words,(model->supvec[i])->words);
		(model->supvec[i])->docnum = -1;
	}
	fclose(modelfl);
	free(line);
	free(words);
	if (com_pro.show_readfile)
	{
		sprintf(temstr, "OK. (%d support vectors read)",(int)(model->sv_num-1));
		printm(temstr);
	}
}
/*read the data from text documents*/
int read_documents(char *docfile,
					DOC  *docs,
					long *label,
					long max_words_doc,
					long ll,
					long *totwords,
					long *totdoc)
{
	char *line;
	DOC doc;
	long dnum=0,wpos,i,dpos=0,dneg=0,dunlab=0;
	long doc_label;
	FILE *docfl;

	line = (char *)my_malloc(sizeof(char)*ll);
	if ((docfl = fopen (docfile, "r")) == NULL)
	{ 
		printe (docfile);  
		return -1;
	}
	
	doc.words = (SVM_WORD *)my_malloc(sizeof(SVM_WORD)*(max_words_doc+10));
	if (com_pro.show_readfile)
	{
		sprintf(temstr,"Reading examples into memory..."); 
		printm(temstr);
	}
	
	dnum=0;
	(*totwords)=0;
	while((!feof(docfl)) && fgets(line,(int)ll,docfl)) {
		if(line[0] == '#') continue;  /* line contains comments */
		if(!parse_document(line,&doc,&doc_label,&wpos,max_words_doc)) 
		{
			sprintf(temstr,"Parsing error in line %ld!",dnum);
			printm(temstr);
		}
		label[dnum]=doc_label;
		if(doc_label > 0) dpos++;
		if (doc_label < 0) dneg++;
		if (doc_label == 0) dunlab++;
		if((wpos>1) && ((doc.words[wpos-2]).wnum>(*totwords))) 
			(*totwords)=(doc.words[wpos-2]).wnum;
		docs[dnum].words = (SVM_WORD *)my_malloc(sizeof(SVM_WORD)*wpos);
		docs[dnum].docnum=dnum;
		for(i=0;i<wpos;i++) 
			docs[dnum].words[i]=doc.words[i];
		docs[dnum].twonorm_sq=doc.twonorm_sq;
		dnum++;  
		if((dnum % 100) == 0&&com_pro.show_readfile) 
		{
			sprintf(temstr,"read %ld..",dnum); 
			printm(temstr);
		}
	} 
	
	fclose(docfl);
	free(line);
	free(doc.words);
	if (com_pro.show_action)
	{
		sprintf(temstr, "OK. (%ld examples read)", dnum);
		printm(temstr);
		sprintf(temstr,"%ld positive, %ld negative, and %ld unlabeled examples.",dpos,dneg,dunlab); 
		printm(temstr);
	}
	(*totdoc)=dnum;
}
/*Parse one  line of data file */
int parse_document(char *line,DOC *doc,long *label,long*numwords,long max_words_doc)
{
	register long wpos,pos;
	long wnum;
	double weight;
	
	pos=0;
	while(line[pos]) 
	{      /* cut off comments */
		if(line[pos] == '#') 
		{
			line[pos]=0;
		}
		else 
		{
			pos++;
		}
	}
	wpos=0;
	if((sscanf(line,"%ld",label)) == EOF) return(0);
	pos=0;
	while(line[pos]==' ') pos++;
	while(line[pos]>' ') pos++;
	while((sscanf(line+pos,"%ld:%lf",&wnum,&weight) != EOF) && 	(wpos<max_words_doc))
	{
		while(line[pos++]==' ');
		while(line[++pos]>' ');
		if(wnum<=0) 
		{ 
			printe ("Feature numbers must be larger or equal to 1!!!"); 
			sprintf(temstr,"LINE: %s",line);
			printm(temstr);
			return (0);
		 
		}
		if((wpos>0) && ((doc->words[wpos-1]).wnum >= wnum))
		{ 
			printe ("Features must be in increasing order!!!"); 
			sprintf(temstr,"LINE: %s",line);
			printm(temstr);
			return (0);
		 
		}
		(doc->words[wpos]).wnum=wnum;
		(doc->words[wpos]).weight=weight; 
		wpos++;
	}
	(doc->words[wpos]).wnum=0;
	(*numwords)=wpos+1;
	doc->docnum=-1;
	doc->twonorm_sq=sprod_ss(doc->words,doc->words);
	return(1);
}
/* grep through file and count number of lines, 
maximum number of spaces per line, and 
longest line. */
int nol_ll(char *file,long *nol,long *wol,long *ll) 
{
	FILE *fl;
	int ic;
	char c;
	long current_length,current_wol;
	
	if ((fl = fopen (file, "r")) == NULL)
	{ 
		printe (file);   
		return -1;
	}
	current_length=0;
	current_wol=0;
	(*ll)=0;
	(*nol)=1;
	(*wol)=0;
	while((ic=getc(fl)) != EOF) 
	{
		c=(char)ic;
		current_length++;
		if(c == ' ') 
		{
			current_wol++;
		}
		if(c == '\n') 
		{
			(*nol)++;
			if(current_length>(*ll)) 
			{
				(*ll)=current_length;
			}
			if(current_wol>(*wol)) 
			{
				(*wol)=current_wol;
			}
			current_length=0;
			current_wol=0;
		}
	}
	fclose(fl);
}

long minl(long a,long b)
{
	if(a<b)
		return(a);
	else
		return(b);
}

long maxl(long a,long b)
{
	if(a>b)
		return(a);
	else
		return(b);
}

long get_runtime() 
{
	clock_t start;
	start = clock();
	return((long)((double)start*100.0/(double)CLOCKS_PER_SEC));
}


int isnan(double a)
{
	return(_isnan(a));
}

void * my_malloc(long size) 
{
	void *ptr;
	ptr=(void *)malloc(size);
	if(!ptr)
	{ 
		printe ("Out of memory!"); 
		return (NULL);
	}
	return(ptr);
}
//print error on screen

void    printe(char* str)
{
	char err[200]="--error--";
	strcat(err,str);
	theApp.ShowM(err);
}

//print message on screen
void	printm(char* str)
{
	theApp.ShowM(str);
}
//custom kernel function
/////////////////////////////////////////////////////////////////
//chen 2001.09.14
/////////////////////////////////////////////////////////////////

double ktt(int ta,int tb,double pa[],double pb[])
{
	int ya,yb;
	ya=((ta-1)%13)+1;
	yb=((tb-1)%13)+1;
	
	if (ya<13&&yb<13) 
		return pa[ta]*pa[ta+1]*pb[tb]*pb[tb+1];
	else return 0.0;
	
}

double kt(int t,double ta[],double tb[])
{
	
	int x,y;
	double sum=0.0;
	x=((t-1)/16)+1;
	y=((t-1)%16)+1;
	if (x>1) 
		sum+=ta[t]*tb[t]*ta[t-16]*tb[t-16];
	if (x>2) 
		sum+=ta[t]*tb[t]*ta[t-32]*tb[t-32];
	if (x>3) 
		sum+=ta[t]*tb[t]*ta[t-48]*tb[t-48];
	if (x<14) 
		sum+=ta[t]*tb[t]*ta[t-48]*tb[t-48];
	if (x<15) 
		sum+=ta[t]*tb[t]*ta[t-32]*tb[t-32];
	if (x<16)
		sum+=ta[t]*tb[t]*ta[t+16]*tb[t+16];
	if (y>3) 
		sum+=ta[t]*tb[t]*ta[t-3]*tb[t-3];
	if (y>2) 
		sum+=ta[t]*tb[t]*ta[t-2]*tb[t-2];
	if (y>1) 
		sum+=ta[t]*tb[t]*ta[t-1]*tb[t-1];
	if (y<14) 
		sum+=ta[t]*tb[t]*ta[t+3]*tb[t+3];
	if (y<15) 
		sum+=ta[t]*tb[t]*ta[t+2]*tb[t+2];
	if (y<16) 
		sum+=ta[t]*tb[t]*ta[t+1]*tb[t+1];
	return sum;
}

double fi(double* tt)
{
	int x,y;
	double sum=0.0;
	for (int t=1;t<=52;t++)
	{
		x=((t-1)/13)+1;
		y=((t-1)%13)+1;
		if (y<13)
			sum+=tt[t]*tt[t+1];
	}
	return sum;
}
double fs(double ta[])
{
	double sum=0.0;
	int x,y;
	for (int i=1;i<256;i++)
	{
		x=((i-1)/16)+1;
		y=((i-1)%16)+1;
		
		if (x<16)
			sum+=ta[i]*ta[i+16];
		if (y<16) 
			sum+=ta[i]*ta[i+1];
	}
	return sum;
}
double sumofword(DOC* a)
{
	double sum=0.0;
	SVM_WORD* pwa=a->words;
	while (pwa->wnum)
	{
		sum+=pwa->weight;
		pwa++;
	}
	return sum;



}
double custom_kernel(KERNEL_PARM *kernel_parm,DOC *a,DOC*b)
{
	double sum=0;
    SVM_WORD *ai,*bj;
    ai=a->words;
    bj=b->words;
    while (ai->wnum || bj->wnum) 
	{
		if(ai->wnum == bj->wnum) 
		{
			sum+=(fabs(ai->weight-bj->weight))*(fabs(ai->weight-bj->weight));
			ai++;bj++;
		}
		else if ((ai!=0) &&(ai->wnum<bj->wnum || bj->wnum==0))
		{
			sum+=fabs(ai->weight)*fabs(ai->weight);
			ai++;
		}
		else if ((bj!=0) &&(bj->wnum<ai->wnum|| ai->wnum==0))
		{
			sum+=fabs(bj->weight)*fabs(bj->weight);
			bj++;
		}
    }
//   case 1: /* polynomial *///
		//return((CFLOAT)pow(kernel_parm->coef_lin*sprod_ss(a->words,b->words)+kernel_parm->coef_const,(double)kernel_parm->poly_degree)); 
    //case 2: /* radial basis function */
	//	return((CFLOAT)exp(-kernel_parm->rbf_gamma*(a->twonorm_sq-2*sprod_ss(a->words,b->words)+b->twonorm_sq)));
    //case 3: /* sigmoid neural net */
	//	return((CFLOAT)tanh(kernel_parm->coef_lin*sprod_ss(a->words,b->words)+kernel_parm->coef_const)); 
    //case 4: /* custom-kernel supplied in file kernel.h*/
	//	return((CFLOAT)custom_kernel(kernel_parm,a,b)); 

/*	
    SVM_WORD *ai,*bj;
    ai=a->words;
    bj=b->words;
	double suma=0.0,sumb=0.0;

    while (ai->wnum ) 
	{
		suma+=ai->weight;
		ai++;
	}
    while (bj->wnum ) 
	{
		sumb+=bj->weight;
		bj++;
	}
	*/
//	double K_rbf=exp(-0.001*(a->twonorm_sq-2*sprod_ss(a->words,b->words)+b->twonorm_sq));
	double K_Laplace=exp(-0.0001*sum);
	double K_poly=pow(sprod_ss(a->words,b->words)+20,3);
//	double K_linear=sprod_ss(a->words,b->words);
	//double sum;
	//double sum=suma*sumb;
	//sum=K_rbf*K_poly;
	//double sum=fabs(pro*pro+pro-tan(pro));
	return K_Laplace*K_poly;

}
void  SetInitParam()
{
		com_param.biased_Hyperplane=1;
		com_param.remove_inconsitant=0;
		com_param.C                =0.0;
		com_param.cost_factor      =1.0;
		com_param.loo              =0;
		com_param.search_depth     = 0;
		com_param.rho           = 	1.0;
		com_param.fraction        =1.0;
		com_param.rbf_gamma        =1.0;
		com_param.poly_c           =0.0;
		com_param.poly_s           =1.0;
		com_param.poly_degree      =1;
		com_param.kernel_type      =0;
		//com_param.user_u   =            pp4.m_strU  ;                            
		com_param.epsion           =0.001;
		com_param.iteration_time   =100;
		com_param.cache_size       =40;
		com_param.new_variable     =com_param.maximum_size;
		com_param.maximum_size     =10;
		com_param.final_test       = 1;

		com_param.blWriteModel=TRUE;
		com_param.Running=FALSE;
		com_param.Finished=TRUE;
		com_param.Close=FALSE;


		//prompt default values
		com_pro.show_action=TRUE;
		com_pro.show_compute_1=TRUE;
		com_pro.show_compute_2=FALSE;
		com_pro.show_compute_3=FALSE;
		com_pro.show_other=FALSE;
		com_pro.show_readfile=FALSE;
		com_pro.show_writefile=FALSE;
		com_pro.show_testresult=TRUE;
		com_pro.show_trainresult=FALSE;
}
