//
// Created by Zeb McCorkle on 7/5/16.
//

#include "config.h"

#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "stack.h"
#include "../stack.h"

void test_stack(void) {
#ifdef TIMER
    clock_t start = TIME;
#endif
    for (uint32_t i = 0; i < RUNS; i++) {
        algo_stack *stack = stack_create();
        stack_push(stack, "Hello, world!");
#ifdef ASSERT
        assert(strcmp(stack_pop(stack), "Hello, world!") == 0);
#endif
        stack_push(stack, "Hello, world!");
        stack_push(stack, "Other thing");
#ifdef ASSERT
        assert(stack_size(stack) == 2);
        assert(strcmp(stack_pop(stack), "Other thing") == 0);
        assert(strcmp(stack_pop(stack), "Hello, world!") == 0);
        assert(stack_size(stack) == 0);
#endif
    }
    printf("Finished without errors!\n");
#ifdef TIMER
    clock_t stop = TIME;
    printf("Runs: %d\nTime taken: %lums\n", RUNS, (stop - start) / (CLOCKS_PER_SEC / 1000));
#endif
}
