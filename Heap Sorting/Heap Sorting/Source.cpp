#include<iostream>
using namespace std;

#define Max 10

class heapSort {
	int arr[Max];
	int Count;

public:
	heapSort() {
		Count = 0;
	}
	void create();
	void siftUp();
	void display();
};


void heapSort::create() {
	int num = 0;
	int i = 0;
	do
	{
		cout << "Enter number: ";
		cin >> num;
		arr[i] = num;

		cout << "Press 1 to continue\nPress 2 to quit" << endl;
		cin >> num;
		i++;
		Count++;
	} while (num==1);
}

void heapSort::siftUp() {
	int temp = 0;
	temp = arr[Count] ;
	for (int i = Count; i >0; i--)
	{
		
		if (arr[i] > arr[i/2]) {
			temp = arr[i];
			arr[i] = arr[i / 2];
			arr[i / 2] = temp;
			i = Count - 1;
		}
		
	}

}
void heapSort::display() {
	for (int  i = 0; i < Count; i++)
	{
		cout << arr[i] << endl;
	}
	
	cout << endl;
}

int main() {
	heapSort H;
	H.create();
	H.display();
	H.siftUp();
	H.display();
}