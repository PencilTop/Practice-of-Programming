#include <stdio.h>
#include <stdlib.h>
#define NELEMS(array) (sizeof(array) / sizeof(array[0]))

void swap(int[], int, int);
void quicksort(int[], int);
//void prtarray(int[]);

int main(int argc, char *argv[]) {
   int v[] = {1, 4, -5, 12, 98, 8, 965, 04, -144};
   quicksort(v, NELEMS(v));
   /*prtarray(v);*/
   //for (int i = 0; i < NELEMS(v); i++)
    //printf("%10d", v[i]);
}

void quicksort(int v[], int n) {
    int i, last;
    if (n <= 1) return;
    swap(v, 0, rand() * n);
    last = 0;
    for (i = 1; i < n; i++) 
        if (v[i] < v[0])
            swap(v, ++last, i);
    swap(v, 0, last);
    quicksort(v, last);
    quicksort(v + last + 1, n - last - 1);
}

void swap(int v[], int i, int j) {
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;

}

/*
void prtarray(int array[]) {
    for (int i = 0; i < NELEMS(array); i++) {
        if (i != 0 && i % 7 == 0) printf("\n");
        printf("%10d", array[i]);
    }
    printf("\n");   
}
*/