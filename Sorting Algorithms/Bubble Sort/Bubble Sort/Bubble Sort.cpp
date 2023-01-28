#include<iostream>
using namespace std;
#define MAX 9
int arr[MAX] = { 54,26,93,17,77,31,44,55,20 };
void bubble_Sort() {
	for (int i = 0; i < MAX-1; i++) {
		for (int j = 0; j < MAX - i-1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				j--;
			}
		}
		
	}
}
void display() {
	for (int i = 0; i < MAX; i++)
	{
		cout << arr[i] << " ";
	}
}

int main() {
	bubble_Sort();
	display();
}