#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define INCLUDE stdio.h

//#define SINGLEOPT
#if defined(SINGLEOPT)
#define NUM_INFILE 2
#else//オプションなし
#define NUM_INFILE 1
#endif

int main(int argc , char *argv[]){
  FILE *input=NULL,*output=NULL;
  char *outname=NULL;
  outname=malloc(strlen(argv[NUM_INFILE])+1);
  strcpy(outname,argv[NUM_INFILE]);

  input=fopen(argv[NUM_INFILE],"r");
  output=fopen();


}
