//
// Created by Zeb McCorkle on 7/5/16.
//

#include "config.h"

#include <stdint.h>
#include <string.h>
#include <printf.h>
#include "hash_map.h"
#include "../hash_map.h"

void test_hash_map(void) {
#ifdef TIMER
    clock_t start = TIME;
#endif
    for (uint32_t i = 0; i < RUNS; i++) {
        hash_map *map = hash_map_create("hi", strlen("hi") + 1, NULL);
        hash_map_set(map, "hi", strlen("hi") + 1, "Hello, world!");
#ifdef ASSERT
        assert(strcmp((char *) hash_map_get(map, "hi", strlen("hi") + 1), "Hello, world!") == 0);
#endif
        hash_map_set(map, "hello", strlen("hello") + 1, (void *) "This is the second element in the map");
#ifdef ASSERT
        assert(strcmp((char *) hash_map_get(map, "hi", strlen("hi") + 1), "Hello, world!") == 0);
        assert(strcmp((char *) hash_map_get(map, "hello", strlen("hello") + 1), "This is the second element in the map") == 0);
#endif
    }
    printf("Finished without errors!\n");
#ifdef TIMER
    clock_t stop = TIME;
    printf("Runs: %d\nTime taken: %lums\n", RUNS, (stop - start) / (CLOCKS_PER_SEC / 1000));
#endif
}