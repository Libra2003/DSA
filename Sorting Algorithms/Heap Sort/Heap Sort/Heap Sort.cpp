#include<iostream>
using namespace std;
#define Max 7
int arr[Max] = {25,22,17,19,11,14,15};


void heapSort() {
	int max;
	for (int i = 0; i < Max; i++) {
		max = arr[1];
		arr[1] = arr[ Max - i ];
	}
}

int main() {
	
}