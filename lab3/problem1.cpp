#include <iostream>
using namespace std;

void printLots(int a[],int b[]) {

	for (int i = 0; i < (sizeof(a) / sizeof(int)) + 1; i++) {
    cout << a[b[i]] << "\n";
	}
}


int main () {
	int P[] = {0,1,2};
	int L[] = {7,8,9};
	
	printLots(L,P);
	
	return 0;
}

//The running time is O(n):
//"i = 0" is O(1), because it will only happen once and is not dependent upon the size of the input.
// "i < (sizeof(a) / sizeof(int)) + 1; i++) {cout << a[b[i]] << "\n"; " will be O(n) because the amount of times these operations will happen is dependent upon the size of P, thus O(n)
// Thus, the overall time complexity of the program will be O(n).

	
			
			
