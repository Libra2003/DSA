#include<iostream>

using namespace std;

int linear_Search(int arr[], int Size, int element, int i) {
	if (element != arr[i] && i < Size) {
		i++;
		return linear_Search(arr, Size, element, i);

	}
	else {
		cout << "Number " << arr[i] << " found at the index " << i << endl;
		return 1;
	}
}



int binary_Search(int arr[], int element, int low, int high, int mid) {
	mid = (high + low) / 2;
	if (low < high) {
		if (arr[mid] < element&&low!=high-1) {
			low = mid;
			return binary_Search(arr, element, low, high, mid);
		}
		else if (arr[mid] > element&&low!=high) {
			high = mid;
			return binary_Search(arr, element, low, high, mid);
		}
	
	}

	if (arr[mid] == element) {
		cout << "Element " << element << " found at the index " << mid << endl;
		return 1;
	}
	else {
		cout << "Number not found" << endl;
		return -1;
	}

}

int main() {
	int num = 0, Size = 9, Capacity = 10;
	int low = 0, high = Size-1, mid = 0;
	int element = 0;
	int i = 0;
	int arr1[10] = { 45,21,56,78.55,55,6,5,56 };
	int arr2[10] = { 4,21,56,78.80,95,100,105,156 };

	do
	{
		cout << "\nPress 1 for linear Search\nPress 2 for Binary_Search" << endl;
		cin >> num;
		switch (num)
		{
		case 1:
			cout << "Enter Number: ";
			cin >> element;
			linear_Search(arr1, Size, element, i);
			break;
		case 2:
			cout << "Enter Number: ";
			cin >> element;
			binary_Search(arr2, element, low, high, mid);
			break;
		default:
			break;
		}

	} while (true);

}