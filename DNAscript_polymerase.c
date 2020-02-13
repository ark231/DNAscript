/*polymerase!!*/
/*|----|  |------|  |       \   / |\       /|
  |    |  |      |  |        \ /  | \     / |
  |----|  |      |  |         V   |  \   /  |
  |       |      |  |         |   |   \ /   |
  |       |------|  |-----    |   |    V    |
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ERR_MALLOC "error: cannot malloc\n"
#define ERR_NOTTRUEEXT "error: This isn't DNAscript source file \n extention must be \"DNA\"or\"dna\"\n"
#define ERR_DAMEGEDDNA "error: This DNA is damaged\nhint: DNAscript source must NOT contain space/tab/newline\n"
/*
#define ERR_MALLOC "error: cannot malloc\n"
#define ERR_MALLOC "error: cannot malloc\n"
#define ERR_MALLOC "error: cannot malloc\n"
#define ERR_MALLOC "error: cannot malloc\n"
*/

#define FOR_LINUX
//#define FOR_WINDOWS
//#define FOR_MAC

#if defined(FOR_LINUX)
#define FILEPATH ""
//これスプライシングの方に付けたほうがいい
#endif
//#define SINGLEOPT

#if defined(SINGLEOPT)
#define NUM_INFILE 2
#else//オプションなし
#define NUM_INFILE 1
#endif

void error(const char*);
int main(int argc , char *argv[]){
  FILE *input=NULL,*output=NULL;
  char *out_name=NULL,*out_ext=NULL,inchartmp;
  int inleng=strlen(argv[NUM_INFILE])+1;
  out_name=(char*)malloc(inleng);
  if(out_name==NULL){
    error(ERR_MALLOC);
  }
  strcpy(out_name,argv[NUM_INFILE]);
  out_name=strtok(out_name,".");
  out_ext=strtok(NULL,".");
  if(strcmp(out_ext,"dna")!=0 && strcmp(out_ext,"DNA")!=0){//拡張子判定
    error(ERR_NOTTRUEEXT);
  }
  sprintf(out_name,"%s.pmrna",out_name);// pre-messengerRNA 伝令RNA前駆体
  input=fopen(argv[NUM_INFILE],"r");
  output=fopen(out_name,"w");
  free(out_name);
  while((inchartmp=fgetc(input))!=EOF){
    switch(inchartmp){
      case 'A':
      case 'a':
        fprintf(output,"U");
        break;
      case 'T':
      case 't':
        fprintf(output,"A");
        break;
      case 'C':
      case 'c':
        fprintf(output,"G");
        break;
      case 'G':
      case 'g':
        fprintf(output,"C");
        break;
      case ' ':
      case '\t':
      case '\n':
        error(ERR_DAMEGEDDNA);
        break;
      default:
        fprintf(output,"%c",inchartmp);
        break;
    }
  }
  fclose(input);
  fclose(output);
  exit(EXIT_SUCCESS);
}

void error(const char *errmsg){
  fprintf(stderr,"%s",errmsg);
  exit(EXIT_FAILURE);
}
