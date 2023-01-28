#include<iostream>
#include<string>
#define Max 5
using namespace std;

struct Circualr_queue {
	int front, rear;
	int arr[Max];

};

Circualr_queue qu;
bool isEmpty() {
	if (qu.front == -1 && qu.rear == -1) {
		return true;
	}
	else {
		return false;
	}
}

bool isFull() {
	if (qu.rear == Max-1 && qu.front ==0 || qu.front == qu.rear+1) {
		return true;
	}
	else {
		return false;
	}
}

void insert_Circular_Q() {
	int num = 0;
	cout << "Enter number: ";
	cin >> num;
	if (qu.rear == -1) {
		qu.front = 0;
		qu.rear++;
		qu.arr[qu.rear] = num;
	}
	else if (qu.rear==Max-1 && qu.front > 0) {
		qu.rear = 0;
		qu.arr[qu.rear] = num;
	}
	else {
		qu.rear++;
		qu.arr[qu.rear] = num;
	}
}
void delete_Circular_Q() {
	if (qu.front == qu.rear - 1) { 
		qu.front = -1;
		qu.rear = -1;
	}
	else if (qu.front == Max) {
		qu.front = 0;
		qu.arr[qu.front] = 0;
		qu.front++;
	}
	else {
		qu.arr[qu.front] = 0;
		qu.front++;

	}

}

void peek() {
	cout <<"Value: "<< qu.arr[qu.rear] << endl;
}

void display() {
	for (int i = 0; i < Max; i++) {
		cout << qu.arr[i] << " ";
	}
}

void mainMenu() {

	cout << "<------------------Deque--------------->" << endl;

	cout << "Press 1 to enque" << endl;
	cout << "Press 2 to dequeue" << endl;
	cout << "Press 3 to dispaly" << endl;
	cout << "Press 4 to peek" << endl;
	cout << "Press 5 to check if the queue is empty or full" << endl;
	cout << "Press 6 to exit" << endl;
}

int main() {
	int num = 0;
	qu.front = -1;
	qu.rear = -1;
	do
	{
		mainMenu();
		cin >> num;
		switch (num)
		{
		case 1:
			if (isFull()) {
				cout << "Queue is Full" << endl;
			}
			else {
				insert_Circular_Q();
			}
			break;
			
		case 2:
			if (isEmpty()) {
				cout << "Queue is Empty" << endl;
			}
			else {
				delete_Circular_Q();
			}
			break;
		case 3:
			if (isEmpty()) {
				cout << "Queue is Empty" << endl;
			}
			else {
				display();
			}
			break;
		case 4:
			if (isEmpty()) {
				cout << "Queue is Empty" << endl;
			}
			else {
				//isPeek();
			}
			break;
		case 5:
			if (isEmpty()) {
				cout << "Queue is empty" << endl;
			}
			else if (isFull()) {
				cout << "Queue is full" << endl;
			}
			else {
				cout << "Queue is neither empty nor full" << endl;
			}
			break;
		case 6:
			exit(1);
		default:
			cout << "Wrong input" << endl;
			break;
		}

	} while (1);
}