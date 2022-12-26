#include <stdio.h>
#include <assert.h>

typedef struct _btnode{
    struct _btnode *root;
    struct _btnode *left;
    struct _btnode *right;
    void *key;
    size_t key_size;
    void *value;
    size_t value_size;
    unsigned int count;
    
} btnode;

typedef struct _btree{
    struct _btnode *root;
    int (*compare_func)(const void*, const void*);
} btree;


int btree_compare_as_int(const void* a, const void* b){
    assert(a != NULL && b != NULL );
    int ia = *(int *)a;
    int ib = *(int *)b;
    if( ia > ib )
        return 1;
    if( ia == ib )
        return 0;
    if( ia < ib )
        return -1;
}

int btree_compare_as_char(const void* a, const void* b){
    assert(a != NULL && b != NULL );
    int ia = *(char *)a;
    int ib = *(char *)b;
    if( ia > ib )
        return 1;
    if( ia == ib )
        return 0;
    if( ia < ib )
        return -1;
}

btree *btree_new(int (*compare_func)(const void*, const void *)){
    btree *tree = malloc(sizeof(*tree));
    tree->root = NULL;
    if(compare_func)
        tree->compare_func = compare_func;
    else
        tree->compare_func = btree_compare_as_int;
    return tree;
}

btnode *btnode_new(void *key, size_t key_size, void *value, size_t value_size){
    btnode *node = malloc(sizeof(*node));
    node->root = NULL;
    node->left = NULL;
    node->right = NULL;
    node->key = key;
    node->key_size = key_size;
    node->value = malloc(value_size);
    memcpy(node->value, value, value_size);
    node->value_size = value_size;
    node->count = 0;
    return node;
}

void btree_add(btree *tree, void *key, size_t key_size, void *value, size_t value_size){

}


btnode *_btnode_recursive_search(btree* tree, btnode *current_node, void* key, size_t key_size){
    if(current_node == NULL || current_node->key == NULL)
        return NULL;
    int compare = tree->compare_func(current_node->key, key);
    assert(compare >= -1 && compare <=1);
    switch(compare){
        case 1:
            return _btnode_recursive_search(tree, current_node->left, key, key_size);
            break;
        case -1:
            return _btnode_recursive_search(tree, current_node->right, key, key_size);
            break;
        case 0:
            return current_node;
            break;
    }
}

btnode *_btnode_recursive_insert(btree* tree, btnode *current_node, void*key, size_t key_size, void *value, size_t value_size){
    if(current_node == NULL){
        // TODO: create new node and return the node
        btnode *new_node = btnode_new(key, key_size, value, value_size);
        return new_node;
    }
    int compare = tree->compare_func(current_node->key, key);
    assert(compare >= -1 && compare <=1);
    switch(compare){
        case 1:
            // the key is smaller than the current_node, we go left
            current_node->left = _btnode_recusive_insert(tree, current_node, key, key_size, value, value_size);
            break;
        case 0:
            // we found the same key
            // increment count and replace data
            current_node->count++;
            free(current_node->value);
            current_node->value = value;
            current_node->value_size = value_size;
            break;
        case -1:
            // the key is larger than the current_node, we go right
            current_node->right = _btnode_recusive_insert(tree, current_node, key, key_size, value, value_size);
            break;
    }
    return current_node;
}

btnode *btree_search(btree *tree, void *key, size_t key_size){
    btnode *node = _btnode_recursive_search(tree, tree->root, key, key_size);
    return node;
}

btnode *btree_insert(btree *tree, void *key, size_t key_size, void *value, size_t value_size){
    btnode * node = _btnode_recursive_insert(tree, tree->root, key, key_size, value, value_size);
    return node;
}