#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "hashtable.h"

// ref: https://planetmath.org/goodhashtableprimes
const int HASH_PRIMES[]={53,97,193,389,769,1543,3079,6151, \
                      12289,24593,49157,98317,196613,393241, \
                      786433,1572869,3145739,6281469l, \
                      12582917,25165843,50331653,\
                      100663319,201326611,402653189,\
                      805306457,1610612741};



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

hashitem *_hashtable_get_bucket(hashtable *table, int key){
    int idx = _hashtable_index(table, key);
    hashitem *bucket = table->_buckets[idx];
    return bucket;
}

hashitem *_hashtable_get_item(hashtable *table, int key){
    hashitem *bucket = _hashtable_get_bucket(table, key);
    while(bucket){
        if(bucket->key == key)
            return bucket;
        bucket = bucket->next;
    }
    return NULL;
}


int hashtable_set(hashtable *table, int key, int value){
    if(table->count > HASH_PRIMES[table->_prime_idx] * 0.75){
        // TODO: rehash
    }
    hashitem *item = _hashtable_get_item(table, key);
    if(item){
        item->value = value;
        return 0;
    }else{
        int idx = _hashtable_index(table, key);
        hashitem *new_item = malloc(sizeof(hashitem));
        new_item->key = key;
        new_item->value = value;
        new_item->next = table->_buckets[idx];
        table->_buckets[idx] = new_item;
        table->count++;
        return 1;
    }   
}

void hashtable_dispose(hashtable *table){
    for(int i=0;i<HASH_PRIMES[table->_prime_idx]; i++){
        if( !table->_buckets[i] )
            continue;
        hashitem *item = table->_buckets[i];
        hashitem *next;
        while(item){
            next = item->next;
            free(item);
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

int *hashtable_get(hashtable *table, int key){
    hashitem *item = _hashtable_get_item(table, key);
    if(!item)
        return NULL;
    return &(item->value);
}


int hashtable_has_key(hashtable *table, int key){
    hashitem *item = _hashtable_get_item(table, key);
    return (item != NULL);
}

int hashtable_del(hashtable *table, int key){
    if(!hashtable_has_key(table, key))
        return 0;
    int idx = _hashtable_index(table, key);
    hashitem *bucket = table->_buckets[idx];
    hashitem *prev = NULL;
    while(bucket){
        if(bucket->key == key){
            if(prev){
                prev->next = bucket->next;
            }else{
                table->_buckets[idx] = NULL;
            }
            free(bucket);
            table->count--;
            return 1;
        }
        prev = bucket;
        bucket = bucket->next;
    }
    return 0;
}

int *hashtable_keys(hashtable *table){
    int *arr = malloc(sizeof(int) * table->count);
    int arr_idx=0;
    hashitem *bucket;
    for(int i=0; i< hashtable_buckets_count(table); i++){
        bucket = table->_buckets[i];
        while(bucket){
            arr[arr_idx] = bucket->key;
            arr_idx++;
            bucket = bucket->next;
        }
    }
    return arr;
}


