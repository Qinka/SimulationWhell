/*  SimulationWhell  */




#ifndef _SIMULATION_H_
#define _SIMULATION_H_

#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>
#include "ulfunc.h"
#include "swdefine.h"

/* Simulation Whell Initialization */
unsigned swInit();
/* Simulation Whell Destory */
unsigned swDestory();
/* alloc memory */
void* swalloc(size_t);
/* free memory */
unsigned swfree(void*);


/* get last error */
unsigned getError();

#endif