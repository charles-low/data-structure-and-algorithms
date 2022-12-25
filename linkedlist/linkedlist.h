/* linkedlist.h 
 * 
 * @author: github.com/charles-low
 * 
 */
#include <stdlib.h>

typedef struct llist_ llist;
typedef struct llnode_ llnode;
typedef struct lliterator_ lliterator;

llist *llist_new(void *data, size_t data_size);
llnode *llnode_new(void *data, size_t data_size);
llnode *llist_last(struct _llist *list);
void llist_dispose(struct _llist *list);
llist *llist_append(struct _llist *list, void *data, size_t data_size);
llist *llist_push(struct _llist *list, void *data, size_t data_size);
llnode *llist_pop(struct _llist *list);
void llnode_dispose(struct _llist *list, struct _llnode *node);
llist *llist_empty(struct _llist *list);
u_int64_t llist_len(struct _llist *list);


//void llist_insert(llnode *node, void *data, size_t data_size);

