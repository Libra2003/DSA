#include<iostream>
using namespace std;
#define Max 10
int arr[Max] = { 7,9,18,19,22,1,6,9,3,5 };

void merge(int mid, int low,int high) {
	int i = low;
	int j = mid+1;
	int k = low;
	int A[20];//Intializing an array

	while (i<=mid&&j<=high)
	{
		if (arr[i] <= arr[j]) {
			A[k] = arr[i];
			i++;
			k++;
		}
		else {
			A[k] = arr[j];
			j++;
			k++;
		}
	}
	while (i<=mid)
	{
		A[k] = arr[i];
		k++;
		i++;
	}
	while (j<=high)
	{
		A[k] = arr[j];
		k++;
		j++;
	}

	for (int i = low;i <=high;i++) {
		arr[i] = A[i];
	}
	
}

void merge_Sort(int low, int high) {
	int mid;
	if (low < high) {
		mid = floor((low + high) / 2);
		merge_Sort(low, mid);
		merge_Sort(mid + 1, high);
		merge(mid, low, high);
	}
}

void display() {
	cout << endl;
	for (int i = 1; i <= Max; i++)
	{
		cout << arr[i] << " ";
	}
}

int main() {

	display();
	merge_Sort(0, Max);
	display();
}