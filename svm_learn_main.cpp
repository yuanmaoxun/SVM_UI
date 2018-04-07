// T3.cpp: implementation of the CT3 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "svm.h"
#include "svm_learn.h"
#include "svm_learn_main.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
static char temstr[200];

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
//char modelfile[200];         /* file for resulting classifier */
void set_learn_parameters(LEARN_PARM* learn_parm,KERNEL_PARM* kernel_parm)
{
 
  
  learn_parm->biased_hyperplane=com_param.biased_Hyperplane;
  learn_parm->remove_inconsistent=com_param.remove_inconsitant;
  learn_parm->skip_final_opt_check=com_param.final_test;
  learn_parm->svm_maxqpsize=com_param.maximum_size;
  learn_parm->svm_newvarsinqp=com_param.new_variable;
  learn_parm->svm_iter_to_shrink=com_param.iteration_time;
  learn_parm->svm_c=com_param.C;
  learn_parm->transduction_posratio=com_param.fraction;
  learn_parm->svm_costratio=com_param.cost_factor;
  learn_parm->svm_costratio_unlab=1.0;
  learn_parm->svm_unlabbound=1E-5;
  learn_parm->epsilon_crit=0.001;
  learn_parm->epsilon_a=1E-15;
  learn_parm->compute_loo=com_param.loo;
  learn_parm->rho=com_param.rho;
  learn_parm->xa_depth=com_param.search_depth;

  kernel_parm->kernel_type=com_param.kernel_type;
  kernel_parm->poly_degree=com_param.poly_degree;
  kernel_parm->rbf_gamma=com_param.rbf_gamma;
  kernel_parm->coef_lin=com_param.poly_s;
  kernel_parm->coef_const=com_param.poly_c;
  //strcpy(kernel_parm->custom,com_param.);
}


int svm_learn_main ()
{  
  DOC *docs;  /* training examples */
  long *label,max_docs,max_words_doc;
  long totwords,totdoc,ll,i;
  KERNEL_CACHE kernel_cache;
  LEARN_PARM learn_parm;
  KERNEL_PARM kernel_parm;
  MODEL model;
  char docfile[200];
  char modelfile[200];
  
  if (com_pro.show_action)
	  printm("begin to compute");
  if (com_pro.show_action)
	printm("Scanning examples...");

  set_learn_parameters(&learn_parm,&kernel_parm);

  strcpy(docfile,com_param.trainfile);
  strcpy(modelfile,com_param.modelfile);
//  kernel_cache_size=com_param.cache_size;


  nol_ll(docfile,&max_docs,&max_words_doc,&ll); /* scan size of input file */
  max_words_doc+=2;
  ll+=2;
  max_docs+=2;


  docs = (DOC *)my_malloc(sizeof(DOC)*max_docs);
  label = (long *)my_malloc(sizeof(long)*max_docs);

  
  read_documents(docfile,docs,label,max_words_doc,ll,&totwords,&totdoc);

  if(kernel_parm.kernel_type == LINEAR) /* don't need the cache */
  { 
    svm_learn(docs,label,totdoc,totwords,&learn_parm,&kernel_parm,NULL,&model);
  }
  else 
  {
    kernel_cache_init(&kernel_cache,totdoc,com_param.cache_size);
    svm_learn(docs,label,totdoc,totwords,&learn_parm,&kernel_parm,&kernel_cache,&model);
    kernel_cache_cleanup(&kernel_cache);
  }

  if (com_param.blWriteModel)
	  write_model(modelfile,&model);

  free(model.supvec);
  free(model.alpha);
  free(model.index);
  for(i=0;i<totdoc;i++) 
    free(docs[i].words);
  free(docs);
  free(label);
  if (com_pro.show_action)
	printm("Cease to compute");	
  return(0);
}

/*---------------------------------------------------------------------------*/

