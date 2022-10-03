#include<iostream>
using namespace std;

int indInsertion(int arr[], int Size, int element, int capacity, int index) {
	if (Size >= capacity) {
		return -1;
	}
	else {
		for (int i = Size;i >= index;i--) {
			arr[i + 1] = arr[i];
		}
		arr[index] = element;
		return 1;
	}

}
void show(int arr[], int n) {
	for (int i = 0;i < n+1;i++) {
		cout << arr[i] << "\n";
	}
}

int main() {
	int arr[10] = { 1,2,3,4,5,6 };
	int Size = 6, element = 45, index = 3;
	indInsertion(arr,Size,element,10,index);
	show(arr, Size);


}