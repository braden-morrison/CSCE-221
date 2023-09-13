#include <iostream>
using namespace std;

void intersection(int a[],int b[], int size1, int size2) {
	

	int L3[size1 + size2];
	int i = 0;
	int j = 0;
	int k = 0;
	//cout << "i = " << i << " j = " << j << " k = " << k << endl;
	//cout << size1 << " " << size2 << endl;
	
	while (i < size1 && j < size2) {
		if (a[i] < b[j]) {
			i++;
		}
		else if (a[i] > b[j]) {
			j++;
		}
		else if (a[i] == b[j]) {
			L3[k] = a[i];
			i++;
			j++;
			k++;
		}
	}
	
	cout << "intersections: ";
	
	for(int z = 0; z < k; z++) {
		cout << L3[z] << " ";
}
cout << endl;

}


int main () {
	int L1[] = {0,1,2,3,4,5,6};
	int L2[] = {4,5,6,7,8,9,10};
	int L1_size = sizeof(L1) / sizeof(int);
	int L2_size = sizeof(L2) / sizeof(int);
	//cout << L1_size << " " << L2_size << endl;
	intersection(L1, L2, L1_size, L2_size);
	
	return 0;
}

//The running time of this program will be O(n+m), where n is the size of list 1 and m is the size of list 2
//The running time is O(m+n) because the while loop will, in the worst case, run until both of the lists are complete searched through
//Thus, the time complexity is dependent upon the size of both of the inputs.
