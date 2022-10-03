#include<iostream>
using namespace std;
#define Max 7
int arr[Max] = { 9,4,8,7,3,1,5 };

void selection_Sort() {
	int min = 0;
	for (int i = 0; i < Max; i++)
	{
		for (int j = i+1; j < Max; j++)
		{
			
			if (arr[min]>arr[j])
			{
				min = j;
			}
		}
		swap(arr[min], arr[i]);

	}
}

void display() {
	for (int i = 0; i < Max; i++)
	{
		cout << arr[i] << " ";
	}
}

int main() {
	selection_Sort();
	display();
}