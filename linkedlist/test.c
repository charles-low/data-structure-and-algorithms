#include "linkedlist.c"
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#define TEST_COUNT 10000000

void test_llist_new(){
    llist *list;
    // double max=0;
    // double min=0;
    // double avg=0;
    // double curtime=0;
    // int t2=0;
    // int t1=0;
    int *data = malloc(sizeof(*data));
    list = llist_new(data, sizeof(*data));
    
    for(int i=0; i<TEST_COUNT; i++){

        data = malloc(sizeof(*data));
        *data = i;
        // t1 = clock();
        llist_append(list, data, sizeof(*data));
        
        // t2 = clock();
        //printf("data: %d\n", *(int *)(list->head->data));
        // if(i % (TEST_COUNT/20)==0)
        //     printf(".");
        //     fflush(stdout);
        
        // curtime = (t2-t1) / 1000;
        // if(i==0){
        //     max = curtime;
        //     min = curtime;
        //     avg = curtime;
        // }else{
        //     max = (max > curtime)? max : curtime;
        //     min = (min < curtime)? min : curtime;
        //     avg = ( (avg * i) + (curtime ) )/ i+1;
        // }
        
    }
    // printf("llist append (%d)\n", TEST_COUNT);
    // printf("min: %f max: %f avg: %f\n", min , max , avg);

    // t1 = clock();
    llist_dispose(list);
    // t2 = clock();
    // curtime = (t2-t1) / 1000;
    // printf("llist_dispose: %f\n", curtime );

    
}

int main(){
    // char* linklist = "link list.";
    // llist *list = llist_new(linklist, sizeof(*linklist));
    // assert(list != NULL);
    // double t1 = clock();
    // for(int i=0; i < TEST_COUNT; i++){
    //     int *j= malloc(sizeof(i));
    //     *j = i;
    //     llist_append(list, &j, sizeof(i));
    // }

    test_llist_new();
    // double t2 = clock();
    // printf("time to append %d items: %f seconds\n", APPEND_COUNT, (t2-t1) / CLOCKS_PER_SEC);

    // for(int i=0; i < TEST_COUNT; i++){
    //     int *j= malloc(sizeof(i));
    //     *j = i;
    //     llist_push(list, &j, sizeof(i));
    // }
}