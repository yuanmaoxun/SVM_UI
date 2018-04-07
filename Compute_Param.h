// Compute_Param.h: interface for the CCompute_Param class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMPUTE_PARAM_H__0155D7A3_9A2A_4712_A5F1_CC2E36C30257__INCLUDED_)
#define AFX_COMPUTE_PARAM_H__0155D7A3_9A2A_4712_A5F1_CC2E36C30257__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CCompute_Param  
{
public:
	CCompute_Param();
public:
	 //Learning options
	double	C;
	double	cost_factor;
	long	biased_Hyperplane;
	long	remove_inconsitant;
 //performance estimations options
	long	loo;
	double	rho;
	long	search_depth;
//transduction option
	double	fraction;
//kernel option
	long	kernel_type;
	long	poly_degree;
	double	rbf_gamma;
	double	poly_s;
	double	poly_c;
//	CString user_u;
//optimization options 
	long	maximum_size;
	long 	new_variable;//2..maximun_size
	double	cache_size;//5..,the larger, the faster
	double	epsion;
	long	iteration_time;//default 100
	int 	final_test;//default 1, to do final test.
//output options

//chen 's parameters

	char	trainfile[200];
	char	modelfile[200];
	char	resultfile[200];
	char	classifyfile[200];
	BOOL	blWriteModel;
	BOOL	Running;
	BOOL	Finished;
	BOOL	Close;

//global variables
	double	Coff[2];

	virtual ~CCompute_Param();

};

#endif // !defined(AFX_COMPUTE_PARAM_H__0155D7A3_9A2A_4712_A5F1_CC2E36C30257__INCLUDED_)
