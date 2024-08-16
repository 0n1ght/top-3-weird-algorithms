// If you thought every algorithm is useful, check this out!
// Bogosort is notorious for its inefficiency, as it randomly shuffles elements until the correct order is achieved.
// Quantum Bogosort takes it a step further by introducing quantum uncertainty into the mix.
// While it’s far from practical, this algorithm showcases the playful side of quantum computing.


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 10

void shuffle(int *array, int size);
bool is_sorted(int *array, int size);
void bogosort(int *array, int size);

int main() {
    int array[SIZE] = {5, 1, 8, 3, 7, 2, 6, 9, 4, 0};
    
    printf("Original array:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    bogosort(array, SIZE);

    printf("Sorted array:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}

void shuffle(int *array, int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

bool is_sorted(int *array, int size) {
    for (int i = 1; i < size; i++) {
        if (array[i] < array[i - 1]) {
            return false;
        }
    }
    return true;
}

void bogosort(int *array, int size) {
    srand(time(NULL));
    while (!is_sorted(array, size)) {
        shuffle(array, size);
    }
}
