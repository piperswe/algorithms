//
// Created by Zeb McCorkle on 7/5/16.
//

#include "config.h"

#include <stdint.h>
#include <string.h>
#include <printf.h>
#include "tree_map.h"
#include "../tree_map.h"

void test_tree_map(void) {
#ifdef TIMER
    clock_t start = TIME;
#endif
    for (uint32_t i = 0; i < RUNS; i++) {
        map_t *map = tree_map_create(0, NULL);
        tree_map_set(map, 0, (void *) "Hello, world!");
#ifdef ASSERT
        assert(strcmp((char *) tree_map_get(map, 0), "Hello, world!") == 0);
#endif
        tree_map_set(map, 1, (void *) "This is the second element in the map");
#ifdef ASSERT
        assert(strcmp((char *) tree_map_get(map, 0), "Hello, world!") == 0);
        assert(strcmp((char *) tree_map_get(map, 1), "This is the second element in the map") == 0);
#endif
    }
    printf("Finished without errors!\n");
#ifdef TIMER
    clock_t stop = TIME;
    printf("Runs: %d\nTime taken: %lums\n", RUNS, (stop - start) / (CLOCKS_PER_SEC / 1000));
#endif
}