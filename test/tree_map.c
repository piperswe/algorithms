//
// Created by Zeb McCorkle on 7/5/16.
//

#include "config.h"

#include <stdint.h>
#include <string.h>
#include <printf.h>
#include <stdlib.h>
#include "tree_map.h"
#include "../tree_map.h"

void test_tree_map(void) {
    srand(TIME);
#ifdef TIMER
    clock_t start = TIME;
#endif
    for (uint32_t i = 0; i < RUNS; i++) {
        map_t *map = tree_map_create();
        int helloWorld = rand();
        tree_map_set(map, helloWorld, "Hello, world!");
#ifdef ASSERT
        assert(strcmp((char *) tree_map_get(map, helloWorld), "Hello, world!") == 0);
#endif
        int secondElement = rand();
        tree_map_set(map, secondElement, "This is the second element in the map");
#ifdef ASSERT
        assert(strcmp((char *) tree_map_get(map, helloWorld), "Hello, world!") == 0);
        assert(strcmp((char *) tree_map_get(map, secondElement), "This is the second element in the map") == 0);
        assert(tree_map_size(map) == 2);
#endif
        tree_map_remove(map, secondElement);
#ifdef ASSERT
        assert(strcmp((char *) tree_map_get(map, helloWorld), "Hello, world!") == 0);
        assert(tree_map_get(map, secondElement) == NULL);
        assert(tree_map_size(map) == 1);
#endif
    }
    printf("Finished without errors!\n");
#ifdef TIMER
    clock_t stop = TIME;
    printf("Runs: %d\nTime taken: %lums\n", RUNS, (stop - start) / (CLOCKS_PER_SEC / 1000));
#endif
}
