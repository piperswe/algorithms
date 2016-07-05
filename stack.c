//
// Created by Zeb McCorkle on 7/5/16.
//

#include "stack.h"
#include <stdio.h>

algo_stack *stack_create() {
    algo_stack *new = malloc(sizeof(algo_stack));
    new->set = false;
    new->value = NULL;
    new->next = NULL;
    return new;
}

void *stack_pop(algo_stack *stack) {
    if (!stack->set) {
        return NULL;
    } else if (stack->next != NULL) {
        void *value = stack->value;
        algo_stack *next = stack->next;
        *stack = *next;
        return value;
    } else {
        stack->set = false;
        return stack->value;
    }
}

void stack_push(algo_stack *stack, void *value) {
    if (!stack->set) {
        stack->value = value;
        stack->set = true;
    } else {
        algo_stack *newTop = malloc(sizeof(algo_stack));
        algo_stack *oldTop = malloc(sizeof(algo_stack));
        *oldTop = *stack;
        newTop->value = value;
        newTop->next = oldTop;
        newTop->set = true;
        *stack = *newTop;
    }
}

size_t stack_size(algo_stack *stack) {
    if (stack->next != NULL) {
        return stack_size(stack->next) + stack->set;
    } else {
        return stack->set;
    }
}
