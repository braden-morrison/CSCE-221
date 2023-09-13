#include <iostream>
#include <assert.h>
using namespace std;


// TODO (student): sort the numbers into nonincreasing order using a merge sort
// TODO (student): implement the following two functions
void merge(int* A, int p, int q, int r) {
	int length = r - p + 1; 
	int mergedA[length];
	int i = p; 
	int j = q + 1; 
	int k = 0; 
	while (i <= q && j <= r) {
		if (A[i] >= A[j]) {
			mergedA[k] = A[i];
			i++;
		}
		else {
			mergedA[k] = A[j];
			j++;
		}
		k++;
	}
	while (i <= q) {
		mergedA[k] = A[i];
		k++;
		i++;
	}
	while (j <= r) {
		mergedA[k] = A[j];
		k++;
		j++;
	}
	for (k = 0; k < length; k++) {
		A[k+p] = mergedA[k];
	}
}


void mergeSort(int* A, int p, int r) {
	if (p >= r) {
		return;
	}
	else {
		int q = (p + r)/2;
		mergeSort(A, p, q);
		mergeSort(A, q+1, r);
		merge(A, p, q, r);
	}
}

int main() {
    // Don't modify the main function
    int test[] = {100, 3, 45, 7, 45, 57, 34, 12, 10};
    int sol[] = {100, 57, 45, 45, 34, 12, 10, 7, 3};
    mergeSort(test, 0, 8);

    for (int i = 0; i < 9; i++) 
        assert(test[i]==sol[i]);
	
    cout << "Test passed." << endl;
	
    return 0;
}