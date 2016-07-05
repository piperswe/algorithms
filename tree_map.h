//
// Created by Zeb McCorkle on 7/4/16.
//

#ifndef ALGORITHMS_TREEMAP_H
#define ALGORITHMS_TREEMAP_H

#include "map.h"

map_t *tree_map_create(uint64_t starting_key, void *starting_value);

void tree_map_set(map_t *map, uint64_t key, void *value);

void *tree_map_get(map_t *map, uint64_t key);

#endif //ALGORITHMS_TREEMAP_H
