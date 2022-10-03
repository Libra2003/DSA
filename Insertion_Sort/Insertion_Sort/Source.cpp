#include<iostream>
using namespace std;
#define Max 7
int arr[Max] = {7,91,2,77,3,99,1};

void selection_Sort() {
	int key = 0;
	for (int i = 1; i < Max; i++)
	{
		int j = i - 1;
		key = arr[i];
		while (arr[j]>key)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
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