//
// Created by Zeb McCorkle on 7/5/16.
//

#include "config.h"

#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "hash_map.h"
#include "../hash_map.h"

/*
 * NOT COVERED BY CC0 LICENSE
 *
 * From this StackOverflow answer: http://stackoverflow.com/a/440240/2329281
 */
void gen_random(char *s, const int len) {
    static const char alphanum[] =
            "0123456789"
                    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                    "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < len; ++i) {
        s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    s[len] = 0;
}

void test_hash_map(void) {
    srand(TIME);
    char helloWorld[32];
    char secondElement[32];
    gen_random(helloWorld, 31);
    gen_random(secondElement, 31);
#ifdef TIMER
    clock_t start = TIME;
#endif
    for (uint32_t i = 0; i < RUNS; i++) {
        map_t *map = hash_map_create();
        hash_map_set(map, helloWorld, 32, "Hello, world!");
#ifdef ASSERT
        assert(strcmp((char *) hash_map_get(map, helloWorld, 32), "Hello, world!") == 0);
#endif
        hash_map_set(map, secondElement, 32, "This is the second element in the map");
#ifdef ASSERT
        assert(strcmp((char *) hash_map_get(map, helloWorld, 32), "Hello, world!") == 0);
        assert(strcmp((char *) hash_map_get(map, secondElement, 32), "This is the second element in the map") == 0);
        assert(hash_map_size(map) == 2);
#endif
        hash_map_remove(map, secondElement, 32);
#ifdef ASSERT
        assert(strcmp((char *) hash_map_get(map, helloWorld, 32), "Hello, world!") == 0);
        assert(hash_map_get(map, secondElement, 32) == NULL);
        assert(hash_map_size(map) == 1);
#endif
    }
    printf("Finished without errors!\n");
#ifdef TIMER
    clock_t stop = TIME;
    printf("Runs: %d\nTime taken: %lums\n", RUNS, (stop - start) / (CLOCKS_PER_SEC / 1000));
#endif
}
