#include<iostream>
using namespace std;
#define Max 10
struct Node {
	int re;
	int arr[Max];
	int fr;
};


bool isEmpty(Node *de) {
	if (de->re == de->fr) {
		return true;
	}
	else {
		return false;
	}
}

bool isFull(Node* de) {
	if (de->re == Max) {
		return true;
	}
	else {
		return false;
	}
}

void front_enqueue(Node* de) {
	if (isFull(de)) {
		cout << "Queue is Full" << endl;
	}
	else {
		int num = 0;
		cout << "\nEnqeue: ";
		cin >> num;
		if (isEmpty(de)) {
 			de->arr[de->fr] = num;
			de->re++;
		}
		else {
			for (int i = de->re; i > de->fr; i--)
			{
				de->arr[i] = de->arr[i - 1];
			}
			de->re++;
			de->arr[de->fr] = num;
		}

	}
}

void rear_enqueue(Node* de) {
	if (isFull(de)) {
		cout << "Queue is Full" << endl;
	}
	else {
		int num = 0;
		cout << "Enqueue: ";
		cin >> num;
		de->arr[de->re] = num;
		de->re++;

	}

}

Node*front_deque(Node* de) {
	if (isEmpty(de)) {
		cout << "Node is Empty" << endl;
	}
	else {
		de->arr[de->fr] = 0;
		de->fr++;
	}
	return de;

}

Node* rear_deque(Node* de) {
	if (isEmpty(de)) {
		cout << "Node is Empty" << endl;
	}
	else {
		de->arr[de->re-1] = 0;
		de->re--;
	}
	return de;
}

int peek(Node* de) {
	if (isEmpty(de)) {
		cout << "deque is Empty" << endl;
	}
	else {
		return de->arr[de->fr];
	}
}

void display(Node* de) {
	if (isEmpty(de)) {
		cout << "deque is empty" << endl;
	}
	else {
		for (int i = de->fr; i < de->re; i++)
		{
			cout << de->arr[i] << endl;

		}
	}
	
}

int main() {
	int choice = 0;
	Node* ptr = new Node();

	do
	{
		cout << "\nPress 1 to enqueue\nPress 2 to deque\nPress 3 to check see if queue is empty or not\nPress 4 to see if queue is full or not " <<
			"\nPress 5 to display\nPress 0 to quit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: {
			do
			{
				cout << "\n\nPress 1 to for front_enqueue\nPress 2 for rear_enqeue\nPress 3 to quit" << endl;
				cin >> choice;
				switch (choice)
				{
				case 1: {
					front_enqueue(ptr);
					break;
				}
				case 2: {
					rear_enqueue(ptr);
					break;
				}
				case 3:
					break;
				default:
					cout << "Plz enter correct input" << endl;
					break;
				}
			} while (choice!=3);

			break;
		}
		case 2: {
			do
			{
				cout << "\n\nPress 1 to for front_enqueue\nPress 2 for rear_enqeue\nPress 3 to quit" << endl;
				cin >> choice;
				switch (choice)
				{
				case 1: {
					front_deque(ptr);
					break;
				}
				case 2: {
					rear_deque(ptr);
					break;
				}
				case 3:
					break;
				default:
					cout << "Plz enter correct input" << endl;
					break;
				}
			} while (choice != 3);
			break;
		}
		case 3: {
			if (isEmpty(ptr))
			{
				cout << "Queue is Empty" << endl;
			}
			else {
				cout << "Queue is not empty" << endl;
			}
			break;
		}
		case 4: {
			if (isFull(ptr))
			{
				cout << "Queue is FULL" << endl;
			}
			else {
				cout << "Queue is not full" << endl;
			}
			break;
		}
		case 5: {
			display(ptr);
			break;
		}
		case 0: {
			exit(0);
		}
		default:
			cout << "Plz give the right input" << endl;
			break;
		}

	} while (choice != 0);
}