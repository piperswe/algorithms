//
// Created by Zeb McCorkle on 7/5/16.
//

#ifndef ALGORITHMS_STACK_H
#define ALGORITHMS_STACK_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct stack {
    void *value;
    struct stack *next;
    bool set;
} algo_stack;

algo_stack *stack_create();

void *stack_pop(algo_stack *stack);

void stack_push(algo_stack *stack, void *value);

size_t stack_size(algo_stack *stack);

#endif //ALGORITHMS_STACK_H
