/* linkedlist.c
 * 
 * @author: github.com/charles-low
 * 
 */
#include <stdlib.h>

typedef struct _llnode {
    struct _llnode *prev;
    struct _llnode *next;
    void *data;
    size_t data_size;
} llnode;

typedef struct _llist {
    struct _llnode *head;
    struct _llnode *tail;
    u_int64_t length;
} llist;


llnode *llnode_new(void *data, size_t data_size){
    struct _llnode *node = malloc(sizeof(*node));
    node->data = data;
    node->data_size = data_size;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

llist *llist_new(void *data, size_t data_size){
    struct _llist *list = malloc(sizeof(*list));
    list->length = 0;
    list->head = llnode_new(data, data_size);
    list->tail = list->head;
    list->length++;
    return list;
}

llnode *llist_last(struct _llist *list){
    struct _llnode *node = list->head;
    while(node->next != NULL)
        node = node->next;
    return node;
}


llist *llist_empty(struct _llist *list){
    struct _llnode *node = list->head;
    struct _llnode *next;
    while(node != NULL){
        next = node->next;
        if(node->data != NULL){
            free(node->data);
            //node->data = NULL;
        }
        free(node);
        node = next;
    }
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
    return list;
}

void llist_dispose(struct _llist *list){
    llist_empty(list);
    free(list);
}

llist *llist_append(struct _llist *list, void *data, size_t data_size){
    struct _llnode *last = list->tail;
    last->next = llnode_new(data, data_size);
    last->next->prev = last;
    list->length++;
    list->tail = last->next;
    return list;
}

llist *llist_push(struct _llist *list, void *data, size_t data_size){
    struct _llnode *head = list->head;
    struct _llnode *new_head = llnode_new(data, data_size);
    new_head->next = head;
    head->prev = new_head;
    list->head = new_head;
    list->length++;
    return list;
}

llnode *llist_pop(struct _llist *list){
    llnode *node = list->tail;
    llnode *prev = node->prev;
    prev->next = NULL;
    node->prev = NULL;
    list->length--;
    list->tail = prev;
    return node;
}

// TODO: the list structure can be messed up by user, need to redesign.
void llnode_dispose(struct _llist *list, struct _llnode *node){
    struct _llnode *next = node->next;
    struct _llnode *prev = node->prev;
    if(node->next == NULL)
        list->tail = node->prev;
    if(node->data != NULL)
        free(node->data);
    free(node);
    if(prev != NULL)
        prev->next = next;
    if(next != NULL)
        next->prev = prev;
    list->length--;
}


u_int64_t llist_len(struct _llist *list){
    u_int64_t length=0;
    struct _llnode *node = list->head;
    while(node != NULL){
        length++;
        node = node->next;
    }
    list->length = length;
    return length;
}


//void ll_insert(llnode *node, void *data, size_t size);
