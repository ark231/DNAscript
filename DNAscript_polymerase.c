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

int main(int argc , char *argv[]){
  FILE *input=NULL,*output=NULL;
  char *outname=NULL;
  int inleng=strlen(argv[NUM_INFILE])+1;
  outname=(char*)malloc(inleng);
  strcpy(outname,argv[NUM_INFILE]);
  strtok(outname,".");

  input=fopen(argv[NUM_INFILE],"r");
  output=fopen();


}

int error(char *errmsg){
  printf("%s\n",errmsg);
  exit(EXIT_FAILURE);
}
