//
// Created by Zeb McCorkle on 7/5/16.
//

#ifndef ALGORITHMS_CONFIG_H
#define ALGORITHMS_CONFIG_H

// I recommend only using one. Assert makes it slower.
#define ASSERT
#define TIMER

#ifdef ASSERT
# include <assert.h>
#endif

#include <time.h>
#define TIME clock()
#define RUNS (1000000)

#endif //ALGORITHMS_CONFIG_H
