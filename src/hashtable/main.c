#include <stdio.h>
#include "hashtable.c"

int main(){
    hashtable *table = hashtable_new();
    hashtable_add(table,1,1);
    hashtable_add(table,2,2);
    hashtable_print(table);
    fflush(stdout);
    hashtable_dispose(table);
    return 0;
}
