#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct point {
    int x, y;
} Point;

int globalVariable = 50;

int SecondLargest(int A[], int N) {
    int largest = A[0];
    int secondLargest = 0;
    for (int idx = 1; idx < N; idx++){
        if(largest < A[idx]) {
            secondLargest = largest;
            largest = A[idx];
        }
        else if (secondLargest < A[idx])
            secondLargest = A[idx];
    }
    return secondLargest;
}

int * CreateArray(int size) {
    return (int*)malloc(sizeof(int) * size);

}

double Distance(Point* p1, Point* p2) {
    return sqrt(pow((p1->x - p2->x), 2) + pow((p1->y - p2->y), 2));
}
void PrintArray(int A[], int size) {

    for (int idx = 0; idx <size; idx++)
        printf("%d ", A[idx]);
        printf("\n");
}

void Reassign(int** Ptr) {
    *Ptr = &globalVariable;
}

void main(){
    int arrayA[] = { 3, 33,7,13,5,2};
    int* newArray = NULL;
    Point p1, p2;
    int localVar = 15;
    int* localVarPtr = &localVar;

    printf("Array A: ");
    PrintArray(arrayA, 6);
    printf("Second Largest of A: %d\n", SecondLargest(arrayA, 6));

    newArray = CreateArray(8);
    printf("New Array: ");
    PrintArray(newArray, 8);

    p1.x = 1;
    p1.y = 1;
    p2.x = 11;
    p2.y = 17;
    printf("Distance: %4.2f\n", Distance(&p1, &p2));

    printf("Value of localVarPtr: %d\n", *localVarPtr);
    Reassign(&localVarPtr);
    printf("Value of localVarPtr: %d\n", *localVarPtr);
}