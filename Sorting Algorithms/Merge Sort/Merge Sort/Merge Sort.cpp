#include<iostream>
using namespace std;
#define Max 5
int arr[Max] = { 9,3,17,2,5 };

void  merge(int low, int mid, int high) {
	int i, j, k, B[8];
	i = low;
	j = mid+1;
	k = low;
	while (i<=mid&&j<=high)
	{
		if (arr[i] < arr[j]) {
			B[k] = arr[i];
			i++;
			k++;
		}
		else {
			B[k] = arr[j];
			j++;
			k++;
		}
	}
	while (i<=mid)
	{
		B[k] = arr[i];
		i++;
		k++;

	}
	while (j <= high) {
		B[k] = arr[j];
		j++;
		k++;
	}
	for (int i = low; i <= high; i++) {
		arr[i] = B[i];
	}

}
void merge_Sort(int arr[],int low,int high) {
	int mid;
	if (low < high) {
		mid = floor((low + high) / 2);
		merge_Sort(arr, low, mid);
		merge_Sort(arr, mid+1, high);
		merge(low, mid, high);
	}
}

void display() {
	for (int i = 0; i < Max; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int low = 0, high = Max;
	display();
	merge_Sort(arr, 0, Max);
	display();

}