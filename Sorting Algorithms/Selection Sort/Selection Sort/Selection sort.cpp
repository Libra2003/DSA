#include<iostream>
using namespace std;


int arr[7] = { 5,4,10,1,6,2,5 };
void Selection_Sort(int length) {
	int min = 0;
	for (int i = 0; i < length; i++) {
		int j = i + 1;
		min = i;
		while (j<length)
		{
			if (arr[j] < arr[min]) {
				min = j;
			}
			j++;
		}
			swap(arr[min], arr[i]);	
	}
}

void display(int length) {
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	
}

int main() {
	int lenght = 7;
	Selection_Sort(lenght);
	display( lenght);
}
