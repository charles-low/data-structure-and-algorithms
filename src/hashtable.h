#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define HASHTABLE_MAX_SIZE = 0X7FFFFFFF;

extern const int HASH_PRIMES[];

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

hashtable *hashtable_new();
int _hashtable_index(hashtable *table, int hash);
hashitem *_hashtable_get_bucket(hashtable *table, int key);
hashitem *_hashtable_get_item(hashtable *table, int key);
int hashtable_set(hashtable *table, int key, int value);
int *hashtable_get(hashtable *table, int key);
void hashtable_dispose(hashtable *table);
int hashtable_buckets_count(hashtable *table);
void hashtable_print(hashtable *table);
int hashtable_del(hashtable *table, int key);
int *hashtable_keys(hashtable *table);
int hashtable_has_key(hashtable *table, int key);