#include "../include/simulationwhell.h"




/* data and pointer */

typedef struct{
  void* pointer;
  void* next;
}Memory;
/* the head of list */
void *listHead=0;
/* is initialized */
bool isInit = false;


unsigned __error=0;
unsigned pullerror(unsigned x)
{
  __error = x;
  return 0;
}

/* Simulation Whell Initialization */
unsigned swInit()
{
  if(isInit) return _ALREADY_INIT;
  listHead = 0;
  isInit = true;
  return FUNC_FINISH_;
}
/* Simulation Whell Destory */
unsigned swDestory()
{
  if(listHead) return _NEED_FREE;
  return FUNC_FINISH_;
}
/* alloc memory */
void* swalloc(size_t t)
{
  if(!isInit) return pullerror(_NEED_INIT);
  Memory* tmp = malloc(sizeof(Memory));
  if (!tmp) return pullerror(MEMORY_ALLOC_FAIL);
  tmp->next = listHead;
  listHead = tmp;
  tmp->pointer = malloc(t);
  return (tmp->pointer);
}
/* free memory */
unsigned swfree(void* p)
{
  void *cur=listHead;
  if (p == ((Memory*)listHead)->pointer)
  {
    free(p);
    listHead = ((Memory*)listHead)->next;
    return FUNC_FINISH_;
  }
  else while(cur)
  {
    if((((Memory*)cur)->next) == p)
    {
      free(((Memory*)((Memory*)cur)->next)->pointer);
      Memory *tmp = ((Memory*)cur)->next;
	  ((Memory*)cur)->next = ((Memory*)((Memory*)cur)->next)->next;
      free(tmp);
      return FUNC_FINISH_;
    }
    cur = ((Memory*)cur)->next;
  }
  return _FREE_FAIL;
}
/* free all */
unsigned swfreeallStep(void* p)
{
  if(((Memory*)p)->next)
  {
    return swfree(p);
  }
  else
  {
    return swfreeallStep(((Memory*)p)->next);
  }
}
unsigned swfreeall()
{
  return swfreeallStep(listHead);
}


/* get last error */
unsigned getError()
{
  return __error;
}
