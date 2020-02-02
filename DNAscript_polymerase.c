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

//#define SINGLEOPT
#if defined(SINGLEOPT)
#define NUM_INFILE 2
#else//オプションなし
#define NUM_INFILE 1
#endif

void error(const char*);
int main(int argc , char *argv[]){

  FILE *input=NULL,*output=NULL;
  char *out_name=NULL,*out_ext=NULL;
  int inleng=strlen(argv[NUM_INFILE])+1;
  out_name=(char*)malloc(inleng);
  if(out_name==NULL){
    error("error: cannot malloc\n");
  }
  strcpy(out_name,argv[NUM_INFILE]);
  out_name=strtok(out_name,".");
  out_ext=strtok(NULL,".");
  if(strcmp(out_ext,"dna")!=0 && strcmp(out_ext,"DNA")!=0){
    error("error: This isn't DNAscript source file \n extention must be \"DNA\"or\"dna\"\n");
  }
  input=fopen(argv[NUM_INFILE],"r");
  output=fopen(out_name,"w");


}

void error(const char *errmsg){
  printf("%s",errmsg);
  exit(EXIT_FAILURE);
}
