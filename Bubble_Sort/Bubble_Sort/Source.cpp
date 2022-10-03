#include<iostream>
using namespace std;
#define Max 6

int arr[Max] = { 7,11,2,3,9,4 };

void bubble_Sort() {
	int max = 1;
	for (int i = 0; i < Max; i++)
	{
		for (int j = 0; j < Max-1-i; j++)
		{
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}

	}
}

void display() {
	for (int i = 0;i < Max;i++) {
		cout << arr[i] << " ";
	}
}

int main() {
	bubble_Sort();
	display();
}