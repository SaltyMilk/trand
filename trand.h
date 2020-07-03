#ifndef TRAND_H
 #define TRAND_H

  #ifndef DEF_NTHREAD
	#define DEF_NTHREAD 4
  #endif

#include <pthread.h>
#include <time.h>
#include <stdlib.h>

int ntrand(unsigned long long n);
int trand();
int strand();

#endif
