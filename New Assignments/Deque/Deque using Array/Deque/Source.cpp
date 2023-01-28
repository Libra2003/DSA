#include<iostream>
using namespace std;
#define Max 10

struct Deque {
	int data;
	int arr[Max];
	int rear;
	int fornt;
};

Deque de;

bool isEmpty() {
	if (de.rear==0) {
		return true;
	}
	else {
		return false;
	}
}
bool isFull() {
	if (de.fornt == 0&& de.rear == Max)
	{
		return true;
	}
	else {
		return false;
	}
}

void pushFront() {
	int num = 0;
	if (isFull()) {
		cout << "deque is full" << endl;
	}
	else {
		cout << "Enter the number: ";
		cin >> num;

		if (isEmpty()) {
			de.arr[de.fornt] = num;
			de.rear++;
		}
		else { 

			for (int i = de.rear; i >= de.fornt; i--) {
				de.arr[i + 1] = de.arr[i];
			}
			de.arr[de.fornt] = num;
			de.rear++;
		}
	}	
}
void pushRear() {
	int num = 0;
	if (isFull()) {
		cout << "Deque is full" << endl;
	}
	else {
		
		cout << "Enter the number: ";
		cin >> num;
			de.arr[de.rear] = num;
			de.rear++;	
	}	
}

int popFront() {
	int num = 0;
	if (isEmpty()) {
		cout << "deque is empty" << endl;
	}
	else {
		int num = de.arr[de.fornt];
		if (de.fornt == de.rear - 1) {
			de.arr[de.fornt] = 0;
			de.fornt = 0;
			de.rear = 0;
			
		}
		else {
			de.arr[de.fornt] = 0;

			de.fornt++;
		}
	}
		
	
	return de.arr[de.fornt];
}
int popRear() {
	if (isEmpty()) {
		cout << "deque is empty" << endl;
	}
	else {
		if (de.fornt == de.rear - 1) {
			de.arr[de.rear] = 0;
			de.fornt = 0;
			de.rear = 0;
		}
		de.arr[de.rear] = 0;
		de.rear--;
	}

		
	
	return de.arr[de.rear];
}

void peek() {
	cout << "Value at the front is : " << de.arr[de.fornt] << endl;
	cout << "Value at the rear is : " << de.arr[de.rear-1] << endl;
	
}

void display() {
	//Reverse queue
	for (int i = de.fornt; i < de.rear; i++)
	{
		cout << de.arr[i] << " ";
	}
	cout << endl;
}

void mainMenu() {
	cout << "<------------------Deque--------------->" << endl;

	cout << "Press 1 to push" << endl;
	cout << "Press 2 to pop" << endl;
	cout << "Press 3 to peek" << endl;
	cout << "Press 4 to display" << endl;
	cout << "Press 5 to check wether the deque is full or empty" << endl;
	cout << "Press 6 to exit" << endl;
}

int main() {
	de.fornt = de.rear = 0;
	int num = 0;
	do
	{
		mainMenu();
		cin >> num;
		switch (num)
		{
		case 1:

			if (isFull()) {
				cout << "Deque is full" << endl;
				cout << endl;
			}
			else {
				do
				{
					cout << "Press 1 to PushFront" << endl;
					cout << "Press 2 to PushRear" << endl;
					cout << "Press 3 to exit" << endl;
					cin >> num;
					switch (num)
					{
					case 1:

						pushFront();
						break;
					case 2:

						pushRear();
						break;
					case 3:
						break;
					default:
						cout << "Wrong input" << endl;
						break;
					}

				} while (num != 3);
			}
			
			break;
		case 2:
			if (isEmpty()) {
				cout << "Deque is empty" << endl;
				cout << endl;
			}
			else {
				do
				{

					cout << "Press 1 to popFront" << endl;
					cout << "Press 2 to popRear" << endl;
					cout << "Press 3 to exit" << endl;
					cin >> num;
					switch (num)
					{
					case 1:
						cout << "Number popped: " << popFront() << endl;
						break;
					case 2:
						cout << "Number popped: " << popRear() << endl;
						break;
					case 3:
						break;
					default:
						cout << "Wrong input" << endl;
						break;
					}



				} while (num != 3);
			}
			break;
		case 3:
			if (isEmpty()) {
				cout << "deque is Empty" << endl;
				cout << endl;
			}
			else {
				peek();

			}
			break;
		case 4:
			if (isEmpty()) {
				cout << "deque is Empty" << endl;
				cout << endl;
			}
			else {
				display();

			}
			break;
		case 5:

			if (isEmpty()) {
				cout << "Deque is empty" << endl;
			}
			else if(isFull()) {
				cout << "Deque is Full" << endl;
			}
			else {
				cout << "Deque is neither empty nor Full" << endl;
			}
			cout << endl;
			break;
		default:
			cout << "Wrong input" << endl;
			break;
		}

	} while (num!=6);
}