// Sleep Sort is an odd sorting algorithm that appeals to people who think that naps are beneficial.
// A distinct thread is allocated to each element in the array, and these threads are put to sleep for a duration that corresponds to their values.
// The sequence gets sorted as they awaken. It’s an oddball, yet surprisingly efficient data organization technique.


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define SIZE 10

typedef struct {
    int value;
    int index;
} ThreadArgs;

int sorted_array[SIZE];

void *sleep_sort(void *arg) {
    ThreadArgs *args = (ThreadArgs *)arg;
    sleep(args->value);
    sorted_array[args->index] = args->value;
    free(arg);
    return NULL;
}

int main() {
    int array[SIZE] = {5, 1, 8, 3, 7, 2, 6, 9, 4, 0};
    pthread_t threads[SIZE];
    
    for (int i = 0; i < SIZE; i++) {
        sorted_array[i] = -1;
    }

    for (int i = 0; i < SIZE; i++) {
        ThreadArgs *args = (ThreadArgs *)malloc(sizeof(ThreadArgs));
        args->value = array[i];
        args->index = i;
        pthread_create(&threads[i], NULL, sleep_sort, (void *)args);
    }

    for (int i = 0; i < SIZE; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Sorted array:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", sorted_array[i]);
    }
    printf("\n");

    return 0;
}
