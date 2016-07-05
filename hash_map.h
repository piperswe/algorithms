//
// Created by Zeb McCorkle on 7/5/16.
//

#ifndef ALGORITHMS_HASH_MAP_H
#define ALGORITHMS_HASH_MAP_H

#include <stddef.h>
#include "tree_map.h"

typedef tree_map hash_map;

hash_map *hash_map_create(void *starting_key, size_t starting_key_length, void *starting_value);

void hash_map_set(hash_map *map, void *key, size_t key_length, void *value);

void *hash_map_get(hash_map *map, void *key, size_t key_length);

#endif //ALGORITHMS_HASH_MAP_H
