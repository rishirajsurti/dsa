//Heap Sort
#include <stdio.h>
#include <stdlib.h>
 
struct MaxHeap
{
    int size;
    int* array;
};
 
void swap(int* a, int* b) { int t = *a; *a = *b;  *b = t; }

void maxHeapify(struct MaxHeap* maxHeap, int idx)
{
    int largest = idx;  
    int left = 2*idx + 1;  // left = 2*idx + 1
    int right = 2*idx + 2; // right = 2*idx + 2
 
    // See if left child of root exists and is greater than
    // root
    if (left < maxHeap->size && 
        maxHeap->array[left] > maxHeap->array[largest])
        largest = left;
 
    // See if right child of root exists and is greater than
    // the largest so far
    if (right < maxHeap->size && 
        maxHeap->array[right] > maxHeap->array[largest])
        largest = right;
 
    // Change root, if needed
    if (largest != idx)
    {
        swap(&maxHeap->array[largest], &maxHeap->array[idx]);
        maxHeapify(maxHeap, largest);
    }
}
 
struct MaxHeap* createAndBuildHeap(int *array, int size)
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
 
void heapSort(int* array, int size)
{
    struct MaxHeap* maxHeap = createAndBuildHeap(array, size);
 
    while (maxHeap->size > 1)
    {
        swap(&maxHeap->array[0], &maxHeap->array[maxHeap->size - 1]);
        --maxHeap->size;  // Reduce heap size
 
        maxHeapify(maxHeap, 0);
    }
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
 
    printf("Given array is \n");
    printArray(arr, size);
 
    heapSort(arr, size);
 
    printf("\nSorted array is \n");
    printArray(arr, size);
    return 0;
}