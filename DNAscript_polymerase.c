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

void error(char*);
int main(int argc , char *argv[]){

  FILE *input=NULL,*output=NULL;
  char *outname=NULL;
  int inleng=strlen(argv[NUM_INFILE])+1;
  outname=(char*)malloc(inleng);
  if(outname==NULL){
    error("error: cannot malloc");
  }
  strcpy(outname,argv[NUM_INFILE]);
  outname=strtok(outname,".");
  strtok(NULL,".");

  input=fopen(argv[NUM_INFILE],"r");
  output=fopen(outname,w);


}

void error(const char *errmsg){
  printf("%s\n",errmsg);
  exit(EXIT_FAILURE);
}
