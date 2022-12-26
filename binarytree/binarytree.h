

typedef struct _btnode btnode;
typedef struct _btree btree;

int btree_compare_as_int(const void *a, const void *b);
int btree_compare_as_char(const void* a, const void *b);
btree *btree_new(int (*compare_func)(const void*, const void *));
btnode *btnode_new(void *key, size_t key_size, void *value, size_t value_size);
void btree_add(btree *tree, void *key, size_t key_size, void *value, size_t value_size);
btnode *btree_search(btree *tree, void *key, size_t key_size);
btnode *btree_insert(btree *tree, void *key, size_t key_size);