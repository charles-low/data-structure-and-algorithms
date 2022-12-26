#include <stdio.h>
#include <time.h>
#include "binarytree.h"
#define TEST_COUNT 100000
#define RAND_RANGE 100001

int main(){
    int key,val;
    btree *tree = btree_new(NULL);
    srand(time(NULL));

    for(int i=0; i<TEST_COUNT; i++){
        key = rand() % RAND_RANGE;
        val = "lasdjflkasdfjlksdajfsdlkfjldskjfladskdfjlsadfjksdalfjsda";
        //btree_add(tree, key, sizeof(key)

    }
}