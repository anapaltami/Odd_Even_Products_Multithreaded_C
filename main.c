#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int numArray[10];   // global array size 10
int SIZE = 10;
int oddArr[5];  // holds values from odd indexes
int SIZE_O = 5;
int evenArr[5]; // holds values from even indexes
int SIZE_E = 5;

/* Function for thread1 to complete */
void oddProduct(void *thread) {
    printf("Odd indexed array: ");
    int i;
    int prod = 1;
    for (i=0; i<SIZE_O; i++) {
        printf("%d, ", oddArr[i]);    // output number
    }
    printf("\n");
    for (i=0; i<SIZE_O; i++) {
        prod *= oddArr[i];
    }
    printf("The product is: %d\n", prod);
}

/* Function for thread2 to complete */
void evenProduct(void *thread) {
    printf("Even indexed array: ");
    int i;
    int prod = 1;
    for (i=0; i<SIZE_E; i++) {
        printf("%d, ", evenArr[i]);    // output number
    }
    printf("\n");
    for (i=0; i<SIZE_E; i++) {
        prod *= evenArr[i];
    }
    printf("The product is: %d\n", prod);
}

int main() {
    /* Create an array with 10 elements */
    int rand(void);     // declare rand() function
    time_t t;
    srand((unsigned) time(&t));     // initialize random number generator
    int i;
    printf("Whole array is: ");
    for (i=0; i<SIZE; i++) {
        numArray[i] = rand() % 10+1;    // assign random number to numArray[i] from 1-10
        printf("%d, ", numArray[i]);    // output number
    }
    printf("\n");

    /* Put values from even and odd indexes into arrays */
    int j;
    int o = 0;
    int e = 0;
    for (j=0; j<SIZE; j++) {
        if (j%2 == 1) {
            oddArr[o] = numArray[j];
            o++;
        } else {
            evenArr[e] = numArray[j];
            e++;
        }
    }

    /* Create two threads */
    pthread_t tid1, tid2;  // variable for thread ID
    pthread_create(&tid1, NULL, oddProduct, (void*)&tid1);
    pthread_create(&tid2, NULL, evenProduct, (void*)&tid2);
    pthread_exit(NULL);
    return 0;
}
