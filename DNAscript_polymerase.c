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
    error("error: cannot malloc\n");
  }
  strcpy(out_name,argv[NUM_INFILE]);
  out_name=strtok(out_name,".");
  out_ext=strtok(NULL,".");
  if(strcmp(out_ext,"dna")!=0 && strcmp(out_ext,"DNA")!=0){//拡張子判定
    error("error: This isn't DNAscript source file \n extention must be \"DNA\"or\"dna\"\n");
  }
  sprintf(out_name,".pmrna");// pre-messengerRNA 伝令RNA前駆体
  input=fopen(argv[NUM_INFILE],"r");
  output=fopen(out_name,"w");
  while((inchartmp=fgetc(input))!=EOF){
    switch(inchartmp){
      case 'A':
      case 'a':
        fprintf(output,"T");
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
      default:
        fprintf(output,"%c",inchartmp);
        break;
    }
  }


}

void error(const char *errmsg){
  fprintf(stderr,"%s",errmsg);
  exit(EXIT_FAILURE);
}
