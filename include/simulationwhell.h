/*  SimulationWhell  */




#ifndef _SIMULATION_H_
#define _SIMULATION_H_

#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>
#include "ulfunc.h"
#include "swdefine.h"


/* initialize this library */
unsigned swInit(size_t);
/* stop this library */
unsigned swStop();

/* basic function */
/* first function: Hw */
unsigned funcHw();
/* second function: doubleItem */
unsigned funcDouble();
/* third function, */
unsigned funcrd();



/* memory pool */
unsigned memorypoolInit();
unsigned memorypoolDestroy();
unsigned mpDataCounter();
void* mpalloc(size_t);
unsigned mpdestory(void *);
size_t getSize(void *);





#endif
