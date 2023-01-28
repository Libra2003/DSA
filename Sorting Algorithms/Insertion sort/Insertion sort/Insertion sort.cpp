#include<iostream>
using namespace std;
#define Max 10
void insertion_sort(int length) {
	int arr[Max] = { 5,6,3,10,1,2,7,11,6,9 };
	int key;
	for (int i = 1; i < Max-1; i++) {
		key = arr[i];
		int j = i - 1;
		while (j >= 0&&arr[j]>key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
	for (int i = 0; i < Max; i++) {
		cout << arr[i] << " ";
	}
}

int main() {
	int len = 6;
	insertion_sort( len);
}