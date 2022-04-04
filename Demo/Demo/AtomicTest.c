//
//  AtomicTest.c
//  Demo
//
//  Created by Zhuo,Chuncai on 2019/3/5.
//  Copyright © 2019 Zhuo,Chuncai. All rights reserved.
//

#include "AtomicTest.h"
//#include <pthread.h>

typedef struct AtomicStruct {
     int x; //_Atomic
     int y;
} AtomicStruct;

void pthreadFunc(void *arg){
    AtomicStruct *tempStruct = arg;
    
    
    __sync_fetch_and_add(&tempStruct->x,10);
    __sync_fetch_and_add(&tempStruct->y,20);

    __atomic_store(&tempStruct->x, 10, 0);
    
//    __atomic_load_n(&tempStruct->x,10);
//    __atomic_load_n(&tempStruct->y,20);

//    tempStruct->y = 20;
    
}

void atomicTest() {
    pthread_t atomic_thread;
    AtomicStruct tempS = {0};
    
    pthread_create(&atomic_thread, NULL, pthreadFunc, &tempS);
    __sync_synchronize();
    printf("temp->x:%d y:%d",tempS.x,tempS.y);
}

