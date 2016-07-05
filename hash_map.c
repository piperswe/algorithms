//
// Created by Zeb McCorkle on 7/5/16.
//

#include <stdint.h>
#include "hash_map.h"
#include "tree_map.h"

// djb2 algo
__attribute__((always_inline)) uint64_t hash(uint8_t *obj, size_t length) {
    uint64_t hash = 5381;

    for (size_t i = 0; i < length; i++) {
        hash = ((hash << 5) + hash) + obj[i];
    }

    return hash;
}

map_t *hash_map_create() {
    return tree_map_create();
}

void hash_map_set(map_t *map, void *key, size_t key_length, void *value) {
    tree_map_set(map, hash(key, key_length), value);
}

void *hash_map_get(map_t *map, void *key, size_t key_length) {
    return tree_map_get(map, hash(key, key_length));
}

void hash_map_remove(map_t *map, void *key, size_t key_length) {
    tree_map_remove(map, hash(key, key_length));
}

size_t hash_map_size(map_t *map) {
    return tree_map_size(map);
}
