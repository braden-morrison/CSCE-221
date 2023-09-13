#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	time_t start, end;
	time(&start);
	int sum = 0;
	int n = 100000;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			sum = sum + i + j;
		}
	}
	time(&end);
	double time_taken = double(end - start);
    cout << "Time taken by fragment 1 with " << n << " as n is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
	
	
	///frag 2
	time_t start2, end2;
	time(&start2);
	sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j< 2 * i; j++) {
			sum = sum + i + j;
		}
	}
	time(&end2);
	double time_taken2 = double(end2 - start2);
    cout << "Time taken by fragment 2 with " << n << " as n is : " << fixed
         << time_taken2 << setprecision(5);
    cout << " sec " << endl;
return 0;
}