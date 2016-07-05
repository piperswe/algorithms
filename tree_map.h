//
// Created by Zeb McCorkle on 7/4/16.
//

#ifndef ALGORITHMS_TREEMAP_H
#define ALGORITHMS_TREEMAP_H

#include <stdint.h>

typedef struct tree_map {
    struct tree_map *left;
    struct tree_map *right;
    uint64_t key;
    void *value;
} tree_map;

tree_map *tree_map_create(uint64_t starting_key, void *starting_value);

void tree_map_set(tree_map *map, uint64_t key, void *value);

void *tree_map_get(tree_map *map, uint64_t key);

#endif //ALGORITHMS_TREEMAP_H
