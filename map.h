//
// Created by Zeb McCorkle on 7/5/16.
//

#ifndef ALGORITHMS_MAP_H
#define ALGORITHMS_MAP_H

#include <stdint.h>

typedef struct map {
    struct map *left;
    struct map *right;
    uint64_t key;
    void *value;
} map_t;

#endif //ALGORITHMS_MAP_H
