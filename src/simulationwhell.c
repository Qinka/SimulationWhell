#include "../include/simulationwhell.h"




/* data and pointer */

typedef struct {
  void *const pointer;
  Memory * next;
}Memory;
/* the head of list */
void *listHead;
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
  if(isInit) return _ALREADLY_INIT;
  listHead = 0;
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
  if(p == listHead)
  {
    free(p->pointer);
    listHead = p->next;
    free(p);
    return FUNC_FINISH_;
  }
  else while(cur)
  {
    if((cur->next) == p)
    {
      free(cur->next->pointer);
      Memory *tmp = cur->next;
      cur->next = cur->next->next;
      free(tmp);
      return FUNC_FINISH_;
    }
    cur = cur->next;
  }
  return _FREE_FAIL;
}
/* free all */
unsigned swfreeallStep(void* p)
{
  if(p->next)
  {
    return swfree(p);
  }
  else
  {
    return swfreeallStep(p->next);
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
