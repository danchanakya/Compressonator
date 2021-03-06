#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <iostream>
#include <fstream>
#include "Compressonator.h"

using namespace std;

typedef struct
{
    int		DataSize;

    float	TotalError;
    float	AbsError;       //< Total Absolute Error
    float	SqError;        //< Total Squared Error
    float	MeanError;
    float	MeanAbsError;

	// Test results
    double	MSE;			// Mean Square Error	
    float	RMSError;		//< Root Mean Square Error

	double	SSIM;
	double	SSIM_Red;
	double	SSIM_Green;
	double	SSIM_Blue;

	double	PSNR;
	double	PSNR_Red;
	double	PSNR_Green;
	double	PSNR_Blue;

	float	encodeTime;		

	// Pass Conditions
    double	pMSE;			// Mean Square Error	
    float	pRMSError;		//< Root Mean Square Error
	double	pSSIM_Red;
	double	pSSIM_Green;
	double	pSSIM_Blue;
	double	pPSNR;
	float	pencodeTime;	

	// SQL data
	int		maxcount;		// Maxumiun number of test items in the data base
	int		test;

	// BC7 options
	int			nCompressionSpeed;	
	int			dwnumThreads;		
	double		fquality;			
	int			brestrictColour;	
	int			brestrictAlpha;		
	unsigned long	dwmodeMask;		
	
	// for testing 4x4 image only. disable related code whenever necessary
    char srcdecodePattern[17];
    char destdecodePattern[17];
	
	// Compression Type
	char  Compression[128];

	// The source file to test on
	char  SourceFile[128];
	char  FullSourceFile[128];
	char  FullTargetBMP[128];
	char  FullSourceBMP[128];
	char  FullSourceDDS[128];
	char ext[128];			// file extension
	char fname[128];		// just the file name without extension and path
    char dir[128];			// Typically null! But in some special cases user may define a full path for Source File, overiding configuration defaults
    char drive[128];		// Typically null!

}REPORT_DATA;

class MY_REPORT_DATA
{
public:
    MY_REPORT_DATA() {
        memset(&data, 0, sizeof(REPORT_DATA));
    };
    friend ostream& operator<<(ostream& os, const MY_REPORT_DATA& dt) {
        REPORT_DATA my_data = dt.data;
        //os << "Absolute Error: \t"		<< my_data.AbsError << "\n";
        os /*<< "MSE: \t"			*/ << my_data.MSE << "\n";
        os /*<< "SSIM: \t"			*/ << my_data.SSIM << "\n";
        os /*<< "SSIM Blue: \t"		*/ << my_data.SSIM_Blue << "\n";
        os /*<< "SSIM Green: \t"	*/ << my_data.SSIM_Green << "\n";
        os /*<< "SSIM Red: \t"		*/ << my_data.SSIM_Red << "\n";
        /*                       */
        os /*<< "PSNR: \t"			*/ << my_data.PSNR << "\n";
        os /*<< "PSNR Blue: \t"		*/ << my_data.PSNR_Blue << "\n";
        os /*<< "PSNR Green: \t"	*/ << my_data.PSNR_Green << "\n";
        os /*<< "PSNR Red: \t"		*/ << my_data.PSNR_Red << "\n";
        return os;
    };

    REPORT_DATA data;
};
