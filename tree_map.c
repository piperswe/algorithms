//
// Created by Zeb McCorkle on 7/4/16.
//

#include <stddef.h>
#include <stdlib.h>
#include "tree_map.h"
#define SIGNUM(x) ((x) > 0) - ((x) < 0)
#define COMPARE(a, b) SIGNUM((a) - (b))

map_t *tree_map_create() {
    map_t *new_map = (map_t *) malloc(sizeof(map_t));
    if (new_map == NULL) {
        return NULL;
    }
    new_map->key = 0;
    new_map->value = NULL;
    new_map->left = NULL;
    new_map->right = NULL;
    new_map->set = false;
    return new_map;
}

void tree_map_set(map_t *map, uint64_t key, void *value) {
    if (!map->set) {
        map->key = key;
        map->value = value;
        map->set = true;
    } else {
        switch (COMPARE(map->key, key)) {
            case 1:
                if (map->right == NULL) {
                    map->right = tree_map_create();
                    map->right->key = key;
                    map->right->value = value;
                    map->right->set = true;
                } else {
                    tree_map_set(map->right, key, value);
                }
                break;
            case -1:
                if (map->left == NULL) {
                    map->left = tree_map_create();
                    map->left->key = key;
                    map->left->value = value;
                    map->left->set = true;
                } else {
                    tree_map_set(map->left, key, value);
                }
                break;
            case 0:
                map->value = value;
                map->set = true;
                break;
        }
    }
}

void *tree_map_get(map_t *map, uint64_t key) {
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
            if (map->set) {
                return map->value;
            } else {
                return NULL;
            }
    }
    return NULL;
}

void tree_map_remove(map_t *map, uint64_t key) {
    switch (COMPARE(map->key, key)) {
        case 1:
            if (map->right == NULL) {
                return;
            } else {
                tree_map_remove(map->right, key);
                return;
            }
        case -1:
            if (map->left == NULL) {
                return;
            } else {
                tree_map_remove(map->left, key);
                return;
            }
        case 0:
            map->set = false;
    }
}

size_t tree_map_size(map_t *map) {
    if (map == NULL) {
        return 0;
    } else {
        return tree_map_size(map->left) + tree_map_size(map->right) + map->set;
    }
}
