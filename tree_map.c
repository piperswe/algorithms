//
// Created by Zeb McCorkle on 7/4/16.
//

#include <stddef.h>
#include <stdlib.h>
#include "tree_map.h"
#define SIGNUM(x) ((x) > 0) - ((x) < 0)
#define COMPARE(a, b) SIGNUM((a) - (b))

tree_map *tree_map_create(uint64_t starting_key, void *starting_value) {
    tree_map *new_map = (tree_map *) malloc(sizeof(tree_map));
    if (new_map == NULL) {
        return NULL;
    }
    new_map->key = starting_key;
    new_map->value = starting_value;
    new_map->left = NULL;
    new_map->right = NULL;
    return new_map;
}

void tree_map_set(tree_map *map, uint64_t key, void *value) {
    switch (COMPARE(map->key, key)) {
        case 1:
            if (map->right == NULL) {
                map->right = tree_map_create(key, value);
            } else {
                tree_map_set(map->right, key, value);
            }
            break;
        case -1:
            if (map->left == NULL) {
                map->left = tree_map_create(key, value);
            } else {
                tree_map_set(map->left, key, value);
            }
            break;
        case 0:
            map->value = value;
    }
}

void *tree_map_get(tree_map *map, uint64_t key) {
    switch (COMPARE(map->key, key)) {
        case 1:
            if (map->right == NULL) {
                return NULL;
            } else {
                return tree_map_get(map->right, key);
            }
        case -1:
            if (map->left == NULL) {
                return NULL;
            } else {
                return tree_map_get(map->left, key);
            }
        case 0:
            return map->value;
    }
    return (void *) "Oh, no!";
}