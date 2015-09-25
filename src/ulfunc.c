#include "../include/ulfunc.h"
#include <stdio.h>
#include <math.h>
#include "../include/simulationwhell.h"


/* functions */

void fun57db1()
{
  printf("func57db1 is called!\n");
  char * string = (char*)swalloc(sizeof(char)*10);
  if(!string)
  {
    printf("func57db1: alloc memory fail :(\nerror code: %u", getError());
    return;
  }
  printf("Type at most 9 characters.\n");
  scanf("%s",string);
  printf("You typed those: %s",string);
  swfree(string);
}
void fun5ab1()
{
  printf("func5ab1 is called!\n");
  printf("func5ab1 is ended.\n");
}
void funa04e()
{
  printf("funca04e is called!\n");
  fun5ab1();
  printf("***");
}

/* functions */

int func32fd3()
{
  printf("func32fd3 is called!\n");
  void* tmp = swalloc(sizeof(char)*1024);
  if(!tmp)
  {
	unsigned rt = getError();
    printf("func57db1: alloc memory fail :(\nerror code: %u",rt );
    return rt;
  }
  ((char*)tmp)[1023]='\0';
  printf("%s\n",tmp);
  return *(((int*)tmp)+(*((int*)tmp)%1024));
}
int funcd80c()
{
  printf("funcd80c is called!\n");
  return 0x283ab4dd;
}
int func3d88()
{
  printf("func3d88 is called!\n");
  return 0x67abe24dd;
}

/* functions */

double func23aa(double d)
{
  double* dd = (double*)swalloc(sizeof(double));
  *dd = sin(d);
  return sin((double)(int)dd)*sin(*dd)*sin(d)*sin((double)(int)&d);
}
float func783a(float f)
{
  return f* func32fd3();
}
