//
// Created by Zeb McCorkle on 7/5/16.
//

#ifndef ALGORITHMS_HASH_MAP_H
#define ALGORITHMS_HASH_MAP_H

#include <stddef.h>
#include "map.h"

map_t *hash_map_create();

void hash_map_set(map_t *map, void *key, size_t key_length, void *value);

void *hash_map_get(map_t *map, void *key, size_t key_length);

void hash_map_remove(map_t *map, void *key, size_t key_length);

size_t hash_map_size(map_t *map);

#endif //ALGORITHMS_HASH_MAP_H
