/*
 * scrgen.c -- prints (double)a - (double)b
 * Copyright(c) Yukimasa Sugizaki, 2013
 * Licence: GPL
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char* argv[])
{
	char wcr_str[0xff], rcr_str[0xff];
	FILE *wcr, *rcr, *scr;
	if(argc != 4){
		fprintf(stderr, "%s: Invalid the arguments.\n", argv[0]);
		fprintf(stderr, "Specified only %d arguments.\n", argc-1);
		exit(EXIT_FAILURE);
	}
	wcr=fopen(argv[1], "r");
	assert(wcr);
	rcr=fopen(argv[2], "r");
	assert(rcr);
	scr=fopen(argv[3], "w");
	assert(scr);
	fgets(wcr_str, 0xff, wcr);
	fgets(rcr_str, 0xff, rcr);
	do{
		fprintf(scr, "%g\n", atof(wcr_str)-atof(rcr_str));
		fgets(wcr_str, 0xff, wcr);
		fgets(rcr_str, 0xff, rcr);
	}while(!feof(wcr));
	fclose(wcr);
	fclose(rcr);
	fclose(scr);
	return 0;
}
