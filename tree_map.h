//
// Created by Zeb McCorkle on 7/4/16.
//

#ifndef ALGORITHMS_TREEMAP_H
#define ALGORITHMS_TREEMAP_H

#include "map.h"

map_t *tree_map_create();

void tree_map_set(map_t *map, uint64_t key, void *value);

void *tree_map_get(map_t *map, uint64_t key);

void tree_map_remove(map_t *map, uint64_t key);

size_t tree_map_size(map_t *map);

#endif //ALGORITHMS_TREEMAP_H
