#include<iostream>
using namespace std;
const int Size = 10;
struct queue{
	int arr[Size];
	int fr , end;
	
};
queue qu;

bool isFull() {
	if (qu.end==Size-1) {
		return true;
	}
	else {
		return false;
	}
}
bool isEmpty() {
	if (qu.end == qu.fr) {
		return true;
	}
	else {
		return false;
	}
}

void enqueue(int value) {
		qu.end++;
		qu.arr[qu.end] = value;

}

int deQueue() {
	int dlt = -1;
	qu.fr++;
	dlt = qu.arr[qu.fr];
		qu.arr[qu.fr] = 0;
		cout << "item deleted: " << dlt << endl;
		if (qu.fr == qu.end - 1) {
			qu.fr = -1;
			qu.end = -1;
		}
	return dlt;
}
void peek() {
	if (isEmpty()) {
		cout << "Queue is empty" << endl;
	}
	else {
		cout << "Value at the front is: " << qu.arr[qu.fr+1] << endl;
		cout << "Value at the End is: " << qu.arr[qu.end] << endl;
	}
}
void display() {
	if (isEmpty()) {
		cout << "Queue is empty" << endl;
	}
	else {
		for (int i = qu.end; i > qu.fr; i--) {
			cout << qu.arr[i] << " " ;
		}
		cout << endl;
	}
}
void maineMenu() {
	cout << "<------------------Queue--------------->" << endl;
	cout << "Press 1 to Enqueue\nPress 2 to deQueue\nPress 3 to check wither that stack is full or empty\n" <<
		"Press 4 to peek\nPress 5 to display\nPress 6 to exit" << endl;
}

int main() {
	qu.fr = qu.end = -1;
	int num = 0;
	int choice = 0;
	do
	{
		maineMenu();
		cin >> choice;
		switch (choice)
		{
		case 1:
			if (isFull()) {
				cout << "Queue is full" << endl;
			}
			else {
				cout << "Enter the number you want to insert: ";
				cin >> num;
				enqueue(num);
			}
			break;
		case 2:
			if (isEmpty()) {
				cout << "Queue is empty" << endl;
			}
			else {
				deQueue();
			}
			break;
		case 3:
			if (isEmpty()) {
				cout << "Queue is  empty" << endl;
			}
			else if (isFull()) {
				cout << "Queue is Full" << endl;
			}
			else {
				cout << "Queue is neither empty nor full" << endl;
			}
			break;
		case 4:
			
			peek();
			break;
		case 5:
			display();
			break;
		case 6:
			break;
		default:
			cout << "Wrond input plz try again" << endl;
			break;
		}

	} while (choice!=6);
}