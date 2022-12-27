#include <stdio.h>
#include "hashtable.c"

int main(){
    hashtable *table = hashtable_new();
    hashtable_set(table,1,1);
    hashtable_set(table,54,54);
    hashtable_set(table,2,2);
    hashtable_set(table,3,3);
    hashtable_print(table);

    printf("value of key 1 is : %d\n", *hashtable_get(table,1));
    printf("value of key 2 is : %d\n", *hashtable_get(table,2));
    // rest assured the following line will generate exception - check if the return pointer returns NULL before use.
    // return NULL is intentional to distinguish if the value exist in the hashtable
    printf("value of key 3 is : %d\n", *hashtable_get(table,3));
    printf("value of key 54 is : %d\n", *hashtable_get(table,54));
    printf("hashtable count: %d\n", table->count);

    hashtable_del(table, 3);
    printf("table has 3: %d\n", hashtable_has_key(table, 3));
    printf("hashtable count: %d\n", table->count);

    fflush(stdout);
    hashtable_dispose(table);
    return 0;
}
