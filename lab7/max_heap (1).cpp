// A C++ program to demonstrate common Binary Max-Heap Operations

#include<iostream>
#include <assert.h>
using namespace std;

// implement this function to insert the element x into the heap
void insert(int heap[], int& n, int x)
{
	heap[n] = x;
	int i = n;
	while (i > 0 and heap[(i-1)/2] < heap[i]) {
		int j = heap[i];
		int t = heap[(i-1)/2];
		heap[i] = t;
		heap[(i-1)/2] = j;
		i = (i-1)/2;
	}
	n++;
}


// implement this function to remove the root
void remove(int heap[], int& n)
{
	int temp = heap[0];
	heap[0] = heap[n-1];
	n = n - 1;
	int i = 0;
	while (i < n) {
		if ((2*i)+2 < n) {
			if (heap[i] > heap[2*i+1] && heap[i] > heap[2*i+2]) {
			break;
			}	
		else {
			int j;
			if (heap[2*i+1] > heap[2*i+2]) {
				j = (2*i+1);
			} else { 
				j = (2*i+2);
			}
			int t = heap[i];
			int y = heap[j];
			heap[i] = y;
			heap[j] = t;
			i = j;
			}	
		}	
	else {
		if ((2*i+1) < n) {
			if (heap[i] < heap[2*i+1]) {
				int z = heap[i];
				int u = heap[2*i+1];
				heap[i] = u;
				heap[2*i+1] = z;
			}
		}
		break;
	
	}
}
	
	}


int main() 
{
    int heap[100]; // The array to store the max-heap
    int n = 0;  // keep track the number of elements in the heap

    insert(heap, n, 1);
    insert(heap, n, 2);
    insert(heap, n, 4);
    insert(heap, n, 6); 
    insert(heap, n, 10);
    insert(heap, n, 11);
    insert(heap, n, 13);
    insert(heap, n, 15);

    assert(n==8);
    int sol1[] = {15, 13, 11, 6, 4, 2, 10, 1};
    int i = 0;

    for (i = 0; i < 8; i++)
        assert(heap[i]==sol1[i]);

    cout << "Test case 1 passed. " << endl;

    remove(heap, n);
    remove(heap, n);

    int sol2[] = {11, 6, 10, 1, 4, 2};
    for (i = 0; i < 6; i++)
        assert(heap[i]==sol2[i]);

    cout << "Test case 2 passed. " << endl;
    return 0;
}
