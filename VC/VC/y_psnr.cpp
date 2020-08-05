//#define org_qp_confirm
//#define rl_restore_ex1
#define rl_restore_ex2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//Foreman
//#define W 352
//#define H 288

////BQMall
#define W 832
#define H 480
int size = (int)(W*H*1.5);
double psnr(double mse) {
	double psnr = 10 * (log10(255*255/(mse)));
	return psnr;
}
double sum_square_err(unsigned char* orgL_ar, unsigned char* targetL_ar) {
	double mse = 0;
	for (int i = 0; i < W*H; i++) {
		mse += ((orgL_ar[i] - targetL_ar[i])*(orgL_ar[i] - targetL_ar[i]));
	}
	return mse/(W*H);
}

double y_psnr(unsigned char* orgL_ar, FILE *targetL) {
	
	unsigned char *targetL_ar = NULL;
	targetL_ar = (unsigned char *)malloc(sizeof(unsigned char)*size);
	memset(targetL_ar, 0, sizeof(unsigned char)*size);
	fread(targetL_ar, 1, size, targetL);

	double mse = sum_square_err(orgL_ar, targetL_ar);
	return psnr(mse);
}

int main()
{
	
	FILE *orgL = fopen("org_v.yuv", "rb");
	unsigned char* orgL_ar = (unsigned char *)malloc(sizeof(unsigned char)*size);
	memset(orgL_ar, 0, sizeof(unsigned char)*size);
	fread(orgL_ar, 1, size, orgL);

	#ifdef rl_restore_ex1
	FILE *target1 = fopen("img22_11.yuv", "rb");
	FILE *target2 = fopen("img27_11.yuv", "rb");
	FILE *target3 = fopen("img32_11.yuv", "rb");
	FILE *target4 = fopen("img37_11.yuv", "rb");
    #endif
	#ifdef rl_restore_ex2
	//qp images before experiemnt
	//Foreman
	FILE *target1 = fopen("img_org.yuv", "rb");
	FILE *target2 = fopen("img_org_11.yuv", "rb");
	FILE *target3 = fopen("img_org_11_2.yuv", "rb");
	FILE *target4 = fopen("img_org_11_2_7.yuv", "rb");
	FILE *target5 = fopen("img22.yuv", "rb");
	FILE *target6 = fopen("img22_4.yuv", "rb");
	FILE *target7 = fopen("img22_4_6.yuv", "rb");
	FILE *target8 = fopen("img22_4_6_7.yuv", "rb");
	FILE *target9 = fopen("img27.yuv", "rb");
	FILE *target10 = fopen("img27_4.yuv", "rb");
	FILE *target11 = fopen("img27_4_6.yuv", "rb");
	FILE *target12 = fopen("img27_4_6_11.yuv", "rb");
	FILE *target13 = fopen("img32.yuv", "rb");
	FILE *target14 = fopen("img32_8.yuv", "rb");
	FILE *target15 = fopen("img32_8_9.yuv", "rb");
	FILE *target16 = fopen("img32_8_9_2.yuv", "rb");
	FILE *target17 = fopen("img37.yuv", "rb");
	FILE *target18 = fopen("img37_7.yuv", "rb");
	FILE *target19 = fopen("img37_7_2.yuv", "rb");
	FILE *target20 = fopen("img37_7_2_8.yuv", "rb");

	#endif
    #ifdef org_qp_confirm
	FILE *target1 = fopen("22.yuv", "rb");
	FILE *target2 = fopen("27.yuv", "rb");
	FILE *target3 = fopen("32.yuv", "rb");
	FILE *target4 = fopen("37.yuv", "rb");
    #endif

	printf("=====================Y-PSNR=====================\n");
	/*printf("Y-PSNR(22) : %lf\n",y_psnr(orgL_ar,target1));
	printf("Y-PSNR(27) : %lf\n", y_psnr(orgL_ar, target2));
	printf("Y-PSNR(32) : %lf\n", y_psnr(orgL_ar, target3));
	printf("Y-PSNR(37) : %lf\n", y_psnr(orgL_ar, target4));
	*/

	//rl2-Foreman
	/*printf("Y-PSNR(org) : %lf\n", y_psnr(orgL_ar, target1));
	printf("Y-PSNR(org_4) : %lf\n", y_psnr(orgL_ar, target2));
	printf("Y-PSNR(org_4_11) : %lf\n", y_psnr(orgL_ar, target3));
	printf("Y-PSNR(22) : %lf\n", y_psnr(orgL_ar, target4));
	printf("Y-PSNR(22_3) : %lf\n", y_psnr(orgL_ar, target5));
	printf("Y-PSNR(22_3_11) : %lf\n", y_psnr(orgL_ar, target6));
	printf("Y-PSNR(27) : %lf\n", y_psnr(orgL_ar, target7));
	printf("Y-PSNR(27_3) : %lf\n", y_psnr(orgL_ar, target8));
	printf("Y-PSNR(27_3_11) : %lf\n", y_psnr(orgL_ar, target9));
	printf("Y-PSNR(32) : %lf\n", y_psnr(orgL_ar, target10));
	printf("Y-PSNR(32_3) : %lf\n", y_psnr(orgL_ar, target11));
	printf("Y-PSNR(32_3_11) : %lf\n", y_psnr(orgL_ar, target12));
	printf("Y-PSNR(37) : %lf\n", y_psnr(orgL_ar, target13));
	printf("Y-PSNR(37_4) : %lf\n", y_psnr(orgL_ar, target14));
	printf("Y-PSNR(37_4_6) : %lf\n", y_psnr(orgL_ar, target15));
	printf("Y-PSNR(37_4_6_11) : %lf\n", y_psnr(orgL_ar, target16));*/

	//rl2-BQMall
	printf("Y-PSNR(org) : %lf\n", y_psnr(orgL_ar, target1));
	printf("Y-PSNR(org_11) : %lf\n", y_psnr(orgL_ar, target2));
	printf("Y-PSNR(org_11_2) : %lf\n", y_psnr(orgL_ar, target3));
	printf("Y-PSNR(org_11_2_7) : %lf\n", y_psnr(orgL_ar, target4));
	printf("Y-PSNR(22) : %lf\n", y_psnr(orgL_ar, target5));
	printf("Y-PSNR(22_4) : %lf\n", y_psnr(orgL_ar, target6));
	printf("Y-PSNR(22_4_6) : %lf\n", y_psnr(orgL_ar, target7));
	printf("Y-PSNR(22_4_6_7) : %lf\n", y_psnr(orgL_ar, target8));

	printf("Y-PSNR(27) : %lf\n", y_psnr(orgL_ar, target9));
	printf("Y-PSNR(27_4) : %lf\n", y_psnr(orgL_ar, target10));
	printf("Y-PSNR(27_4_6) : %lf\n", y_psnr(orgL_ar, target11));
	printf("Y-PSNR(27_4_6_11) : %lf\n", y_psnr(orgL_ar, target12));

	printf("Y-PSNR(32) : %lf\n", y_psnr(orgL_ar, target13));
	printf("Y-PSNR(32_8) : %lf\n", y_psnr(orgL_ar, target14));
	printf("Y-PSNR(32_8_9) : %lf\n", y_psnr(orgL_ar, target15));
	printf("Y-PSNR(32_8_9_2) : %lf\n", y_psnr(orgL_ar, target16));
	
	printf("Y-PSNR(37) : %lf\n", y_psnr(orgL_ar, target17));
	printf("Y-PSNR(37_7) : %lf\n", y_psnr(orgL_ar, target18));
	printf("Y-PSNR(37_7_2) : %lf\n", y_psnr(orgL_ar, target19));
	printf("Y-PSNR(37_7_2_8) : %lf\n", y_psnr(orgL_ar, target20));
	
	fclose(orgL);
	fclose(target1);
	return -1;
}
