#include "sortAlgorithm.h"
using namespace std;

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int* arr, int& n){  
    int i, j, min_idx;  
  
    // One by one move boundary of unsorted subarray  
    for (i = 0; i < n-1; i++){  
        // Find the minimum element in unsorted array  
        min_idx = i;  
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[min_idx])  
            min_idx = j;  
  
        // Swap the found minimum element with the first element  
        swap(arr[min_idx], arr[i]);  
    }  
}
void bubbleSort(int* arr, int& n){  
    int i, j;  
    for (i = 0; i < n-1; i++)      
      
    // Last i elements are already in place  
    for (j = 0; j < n-i-1; j++){
        if (arr[j] > arr[j+1]){
            swap(&arr[j], &arr[j+1]);  
        }
    }
}  

void insertionSort(int* arr, int n){  
    int i, key, j;  
    for (i = 1; i < n; i++){  
        key = arr[i];  
        j = i - 1;  
  
        /* Move elements of arr[0..i-1], that are  
        greater than key, to one position ahead  
        of their current position */
        while (j >= 0 && arr[j] > key){  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
}

void heapify(int* arr, int n, int i){
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i){
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
 
// main function to do heap sort
void heapSort(int* arr, int n){
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

void merge(int* arr, int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
 
    // Create temp arrays
    int L[n1], R[n2];
 
    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    // Merge the temp arrays back into arr[l..r]
 
    // Initial index of first subarray
    int i = 0;
 
    // Initial index of second subarray
    int j = 0;
 
    // Initial index of merged subarray
    int k = l;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
// l is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int* arr,int l,int r){
    if(l>=r){
        return;//returns recursively
    }
    int m = (l+r-1)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}

int Partition(int* a, int low, int high)
{
	int pivot, index, i;
	index = low;
	pivot = high;
 
	// Getting index of the pivot.
	for(i=low; i < high; i++)
	{
		if(a[i] < a[pivot])
		{
			swap(&a[i], &a[index]);
			index++;
		}
	}
	// Swapping value at high and at the index obtained.
	swap(&a[pivot], &a[index]);
 
	return index;
}
 
// Random selection of pivot.
int RandomPivotPartition(int* a, int low, int high)
{
	int pvt, n, temp;
	n = rand();
	// Randomizing the pivot value in the given subpart of array.
	pvt = low + n%(high-low+1);
 
	// Swapping pivot value from high, so pivot value will be taken as a pivot while partitioning.
	swap(&a[high], &a[pvt]);
 
	return Partition(a, low, high);
}
 
int quickSort(int* a, int low, int high)
{
	int pindex;
	if(low < high)
	{
		// Partitioning array using randomized pivot.
		pindex = RandomPivotPartition(a, low, high);
		// Recursively implementing QuickSort.
		quickSort(a, low, pindex-1);
		quickSort(a, pindex+1, high);
	}
	return 0;
}

int binarySearch(int* a, int item,int low, int high){
    if (high <= low)
        return (item > a[low]) ? (low + 1) : low;
 
    int mid = (low + high) / 2;
 
    if (item == a[mid])
        return mid + 1;
 
    if (item > a[mid])
        return binarySearch(a, item,mid + 1, high);
    return binarySearch(a, item, low, mid - 1);
}
 
// Function to sort an array a[] of size 'n'
void binaryInsertionSort(int* a, int& n){
    int i, loc, j, k, selected;
 
    for (i = 1; i < n; ++i){
        j = i - 1;
        selected = a[i];
 
        // find location where selected sould be inseretd
        loc = binarySearch(a, selected, 0, j);
 
        // Move all elements after location to create space
        while (j >= loc){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = selected;
    }
}

void chooseAlgorithms(int* a, int i, int& DataSize){
    switch (i)
    {
    case 0:
        selectionSort(a,DataSize);
        break;
    case 1:
        mergeSort(a,0,DataSize);
        break;
    case 2:
        heapSort(a,DataSize);
        break;
    case 3:
        quickSort(a,0,DataSize);
        break;
    case 4:
        bubbleSort(a,DataSize);
        break;
    case 5:
        insertionSort(a,DataSize);
    case 6:
        binaryInsertionSort(a,DataSize);
    default:
        break;
    }
}
