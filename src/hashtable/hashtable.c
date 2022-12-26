#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define HASHTABLE_MAX_SIZE = 0X7FFFFFFF;
// ref: https://planetmath.org/goodhashtableprimes
const int HASH_PRIMES[]={53,97,193,389,769,1543,3079,6151, \
                      12289,24593,49157,98317,196613,393241, \
                      786433,1572869,3145739,6281469l, \
                      12582917,25165843,50331653,\
                      100663319,201326611,402653189,\
                      805306457,1610612741};

typedef struct _hashitem {
    int key;
    int value;
    struct _hashitem *next;
} hashitem;

typedef struct _hashtable{
    int count;
    struct _hashitem **_buckets;
    int _prime_idx;
} hashtable;

hashtable *hashtable_new(){
    hashtable *table = malloc(sizeof(*table));  
    table->_prime_idx = 0;
    table->_buckets = calloc(HASH_PRIMES[table->_prime_idx], sizeof(hashitem *));
    table->count = 0;
    return table;
}

int _hashtable_index(hashtable *table, int hash){
    return hash % HASH_PRIMES[table->_prime_idx];
}

void hashtable_add(hashtable *table, int key, int value){
    if(table->count > HASH_PRIMES[table->_prime_idx] * 0.75){
        // TODO: rehash
    }
    int idx = _hashtable_index(table, key);
    
    hashitem *new_item = malloc(sizeof(hashitem));
    new_item->key = key;
    new_item->value = value;
    new_item->next = table->_buckets[idx];

    table->_buckets[idx] = new_item;
    table->count++;
}

void hashtable_dispose(hashtable *table){
    for(int i=0;i<HASH_PRIMES[table->_prime_idx]; i++){
        if( !table->_buckets[i] )
            continue;
        hashitem *item = table->_buckets[i];
        hashitem *next;
        while(item){
            next = item->next;
            free(table->_buckets[i]);
            item = next;
        }
    }
    free(table->_buckets);
    free(table);
}

int hashtable_buckets_count(hashtable *table){
    return HASH_PRIMES[table->_prime_idx];
}

void hashtable_print(hashtable *table){
    printf("[");
    for(int i=0;i<hashtable_buckets_count(table); i++){
        hashitem *bucket = table->_buckets[i];
        while(bucket != NULL){
            printf("%d,", bucket->value);
            bucket = bucket->next;
        }

    }
    printf("]");
}

int main(){
    hashtable *table = hashtable_new();
    hashtable_add(table,1,1);
    hashtable_add(table,2,2);
    hashtable_print(table);
    fflush(stdout);
    hashtable_dispose(table);
    return 0;
}
