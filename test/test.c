//
// Created by Zeb McCorkle on 7/5/16.
//

#include <stdio.h>
#include "tree_map.h"
#include "hash_map.h"
#include "stack.h"

int main(void) {
    printf("Tree map: ");
    test_tree_map();
    printf("Hash map: ");
    test_hash_map();
    printf("Stack: ");
    test_stack();
}
