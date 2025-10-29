#include "int_math.h"
#include <pthread.h>
#include <stdio.h>

int shared = 0;

void* worker(void* arg) {
    add(shared,shared+1);
    return NULL;
}
int main() {
    pthread_t t1, t2;
    pthread_create(&t1, NULL, worker, NULL);
    pthread_create(&t2, NULL, worker, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("shared = %d\n", shared);
    return 0;
}
