#include <bits/stdc++.h>
using namespace std;
void swap(int *x, int *y) 
{ 
	int temp = *x; 
	*x = *y; 
	*y = temp; 
} 
//class MaxHeap 
//{ 
//	int *harr; // pointer to array of elements in heap 
//	int capacity; // maximum possible size of max heap 
//	int heap_size; // Current number of elements in max heap 
//public: 
//	MaxHeap(int a[], int size); // Constructor 
//	void maxHeapify(int i); //To maxHeapify subtree rooted with index i 
//	int parent(int i) { return (i-1)/2; } 
//	int left(int i) { return (2*i + 1); } 
//	int right(int i) { return (2*i + 2); } 
//
//	int extractMax(); // extracts root (maximum) element 
//	int getMax() { return harr[0]; } // Returns maximum 
//
//	// to replace root with new node x and heapify() new root 
//	void replaceMax(int x) { harr[0] = x; maxHeapify(0); } 
//}; 

void MaxHeap(int a[], int size) 
{ 
	heap_size = size; 
	harr = a; // store address of array 
	int i = (heap_size - 1)/2; 
	while (i >= 0) 
	{ 
		maxHeapify(i); 
		i--; 
	} 
} 
void extractMax() 
{ 
	if (heap_size == 0) 
		return INT_MAX; 

	// Store the maximum vakue. 
	int root = harr[0]; 

	// If there are more than 1 items, move the last item to root 
	// and call heapify. 
	if (heap_size > 1) 
	{ 
		harr[0] = harr[heap_size-1]; 
		maxHeapify(0); 
	} 
	heap_size--; 

	return root; 
} 
void maxHeapify(int i) 
{ 
	int l = left(i); 
	int r = right(i); 
	int largest = i; 
	if (l < heap_size && harr[l] > harr[i]) 
		largest = l; 
	if (r < heap_size && harr[r] > harr[largest]) 
		largest = r; 
	if (largest != i) 
	{ 
		swap(&harr[i], &harr[largest]); 
		maxHeapify(largest); 
	} 
} 

// A utility function to swap two elements 


int kthSmallest(int a[],int n,int k){
	MaxHeap(a,k);
	for(int i=k;i<n;i++){
		if(a[i]<getMax())
			replaceMax(a[i]);
	}
	return getMax();
}
int main(){
	  int arr[] = {12, 3, 5, 7, 19}; 
    int n = sizeof(arr)/sizeof(arr[0]), k = 4; 
    cout << "K'th smallest element is " <<  kthSmallest(arr, n, k); 
    return 0; 
}
