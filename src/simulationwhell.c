




#include "../include/simulationwhell.h"

bool isInit = false;


/* initialize this library */
unsigned swInit(size_t s)
{
  if(isInit)
    return _ALLOC_FAIL;
  {
    unsigned tmp = memorypoolInit(s);
    if(!tmp) return tmp;
  }
}
/* stop this library */
unsigned swStop()
{
  if(!isInit) return _ALREADY_DESTORY;
  if(isPoolInit)
  {
    unsigned tmp = memorypoolDestroy();
    if(!tmp) return tmp;

}

/* basic function */
/* first function: Hw */
unsigned funcHw();
/* second function: doubleItem */
unsigned funcDouble();
/* third function, */
unsigned funcrd();



/* memory pool */

void *pool;
size_t poolSize;
size_t poolUsed;
bool isPoolInit = false;


unsigned memorypoolInit(size_t s)
{
  if(isPoolInit) return _ALREADY_INIT;
  void *tmp = malloc(s);
  if (!tmp) return _ALLOC_FAIL;
  pool = tmp;
  poolSize = s;
  poolUsed = 0;
  isInit = true;
  return FUNC_FINISH_;
}
unsigned memorypoolDestroy();
unsigned mpDataCounter();
void* mpalloc(size_t);
unsigned mpdestory(void *);
size_t getSize(void *);
