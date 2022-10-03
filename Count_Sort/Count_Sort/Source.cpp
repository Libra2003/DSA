#include<iostream>
using namespace std;
#define Max 10
int maximum(int arr[],int n) {
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i]>arr[max])
		{
			max = i;
		}
	}
	return arr[max];
}

void count_Sort(int arr[]) {
	int Size = maximum(arr, Max);
	int* B = new int(Size);
	for (int i = 0; i < Max + 1; i++)
	{
		B[i] = 0;
	}
	for (int i = 0; i < Size; i++)
	{
		int j = 0;
		while (j != arr[i])
		{
			
			j++;
			if (j == arr[i]) {
				B[j]++;
				break;
			}
			
		}
	}
	for (int i = 0; i < Max; i++)
	{
		cout << B[i] << " ";
	}
	int k = 0;
	for (int i = 0; i <= Size; i++)
	{
		if (B[i] != 0) {
			arr[k] = i;
			cout << arr[k] << " ";
			B[i] --;
			i--;
			k++;
		}
	}
	cout << endl;
}

void display(int arr[]) {
	for (int i = 0; i < Max; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int arr[10] = {3,1,9,7,1,2,4};
	display(arr);
	count_Sort(arr);
	display(arr);
}