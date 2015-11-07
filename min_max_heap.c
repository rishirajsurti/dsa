//find min max using heapify procedures
//least number of comparisons ever
//see plot.py, heap_vs_linear.png
// https://github.com/rishirajsurti/dsa/blob/master/plot.py
// https://github.com/rishirajsurti/dsa/blob/master/heap_vs_linear.png

/*
Explaination of why this takes only 2*log(n) comparisons:

Here we are not sorting the array using HeapSort.
We are just calling the (Min/Max)Heapify procedure on the array
and printing the first element.

Heapsort takes n*log(n) because it calles Heapify procedures n times.
See here: https://github.com/rishirajsurti/dsa/blob/master/heapsort.c

Here we are calling once for Min and once for Max.
Hence 2*log(n)
*/
#include <stdio.h>
#include <stdlib.h>

struct MaxHeap
{
    int size;
    int* array;
};

void swap(int* a, int* b) { 
    int t = *a;
    *a = *b;
    *b = t; 
}

void maxHeapify(struct MaxHeap* maxHeap, int idx)
{
    int largest = idx;      
    //as index starts from 0
    int left = (2*idx) + 1;  // left = 2*idx + 1
    int right = (2*idx) + 2; // right = 2*idx + 2
 
    if (maxHeap->array[largest] < maxHeap->array[left] &&
        left < maxHeap->size )
        largest = left;
 
    // See if right child of root exists and is greater than
    // the largest so far
    if (maxHeap->array[largest] < maxHeap->array[right] &&
        right < maxHeap->size )
        largest = right;
 
    // Change root, if needed
    if (largest != idx)
    {
        swap(&maxHeap->array[largest], &maxHeap->array[idx]);
        maxHeapify(maxHeap, largest);
    }
}


void minHeapify(struct MaxHeap* maxHeap, int idx)
{
    int least = idx;      
    //as index starts from 0
    int left = (2*idx) + 1;  // left = 2*idx + 1
    int right = (2*idx) + 2; // right = 2*idx + 2
 
    if (maxHeap->array[left] < maxHeap->array[least]  &&
        left < maxHeap->size )
        least = left;
 
    // See if right child of root exists and is greater than
    // the largest so far
    if (maxHeap->array[right] < maxHeap->array[least]  &&
        right < maxHeap->size )
        least = right;
 
    // Change root, if needed
    if (least != idx)
    {
        swap(&maxHeap->array[least], &maxHeap->array[idx]);
        minHeapify(maxHeap, least);
    }
}

 
struct MaxHeap* createAndBuildMaxHeap(int *array, int size)
{
    int i;
    struct MaxHeap* maxHeap = 
              (struct MaxHeap*) malloc(sizeof(struct MaxHeap));
    maxHeap->size = size;   // initialize size of heap
    maxHeap->array = array; // Assign address of first element of array
 
    // Start from bottommost and rightmost internal mode and heapify all
    // internal modes in bottom up way
    for (i = (maxHeap->size - 2) / 2; i >= 0; --i)
        maxHeapify(maxHeap, i);
    return maxHeap;

}


struct MaxHeap* createAndBuildMinHeap(int *array, int size)
{
    int i;
    struct MaxHeap* minHeap = 
              (struct MaxHeap*) malloc(sizeof(struct MaxHeap));
    minHeap->size = size;   // initialize size of heap
    minHeap->array = array; // Assign address of first element of array
 
    // Start from bottommost and rightmost internal mode and heapify all
    // internal modes in bottom up way
    for (i = (minHeap->size - 2) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
    return minHeap;

}


void FindMax(int* array, int size)
{
    printf("\nMax:" );
    struct MaxHeap* maxHeap = createAndBuildMaxHeap(array, size);
 
    printf("%d\n", maxHeap->array[0]);
}
 
void FindMin(int* array, int size)
{
    struct MaxHeap* maxHeap = createAndBuildMinHeap(array, size);
 
    printf("Min: %d\n", maxHeap->array[0]);
}
 

void printArray(int* arr, int size)
{
    int i;
    for (i = 0; i < size; ++i)
        printf("%d ", arr[i]);
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr)/sizeof(arr[0]);
 
    printf("Original array: \n");
    printArray(arr, size);
 
    FindMax(arr, size);

    FindMin(arr, size);
    
    return 0;
}
