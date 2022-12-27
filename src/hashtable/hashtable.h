#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define HASHTABLE_MAX_SIZE = 0X7FFFFFFF;

extern const int HASH_PRIMES[];

typedef struct _hashitem hashitem;
typedef struct _hashtable hashtable;

hashtable *hashtable_new();
int _hashtable_index(hashtable *table, int hash);
void hashtable_add(hashtable *table, int key, int value);
void hashtable_dispose(hashtable *table);
int hashtable_buckets_count(hashtable *table);
void hashtable_print(hashtable *table);
