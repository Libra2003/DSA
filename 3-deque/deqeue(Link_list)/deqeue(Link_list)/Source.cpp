#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
};

Node* front = NULL;
Node* rear = NULL;

bool isEmpty() {
	if (front==NULL)
	{
		return true;
	}
	else {
		return false;
	}
}

bool isFull() {
	Node* newNode = new Node();
	if (newNode==NULL)
	{
		return true;
	}
	else {
		return false;
	}
}

void front_enqueue() {
	if (isFull())
	{
		cout << "Queue is Full" << endl;
	}
	else {
		Node* newNode = new Node();
		cout << "Enqueue: ";
		cin >> newNode->data;
		if (isEmpty())
		{
			rear = front = newNode;
		}
		else {
			Node* temp = front;
			if (rear == front) {
				newNode->next = front;
				rear = front;
				front = newNode;
			}
			else {
				newNode->next = front;
				front = newNode;
			}
		
		}
	}
}

void rear_enqueue() {
	if (isFull())
	{
		cout << "Queue is full" << endl;
	}
	else {
		Node* newNode = new Node();
		cout << "Enqueue: ";
		cin >> newNode->data;
		if (isEmpty())
		{
			rear= newNode;
		}
		else {
			Node* temp = front;
			while (temp->next!=NULL)
			{
				temp = temp->next;
			}
			temp->next = newNode;
			rear = newNode;

		}
	}
}

Node* front_deque() {
	if (isEmpty())
	{
		cout << "Queue is empty" << endl;
	}
	else {
		front = front->next;
	}
	return front;
}

Node* rear_deque() {
	if (isEmpty())
	{
		cout << "Queue is empty" << endl;
	}
	else {
		Node* temp = front;
		Node* Prev = NULL;

		while (temp->next!=NULL)
		{
			Prev = temp;
			temp = temp->next;
		}
		if (Prev == NULL) {
			temp = NULL;
			front = temp;
		}
		else {
			Prev->next = NULL;
			Prev = rear;
		}
		
	}
	return front;
}

void display() {
	if (isEmpty()) {
		cout << "Queue is Empty" << endl;
	}
	else {
		Node* temp = front;
		while (temp!=NULL)
		{
			cout << temp->data << endl;
			temp = temp->next;
		}
	}
}

int main() {
	int choice = 0;

	do
	{
		cout << "\nPress 1 to enqueue\nPress 2 to deque\nPress 3 to check see if queue is empty or not\nPress 4 to see if queue is full or not " <<
			"\nPress 5 to display\nPress 0 to quit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 6: {
			exit(0);

		}
		case 1: {
			do
			{
				cout << "\n\nPress 1 to for front_enqueue\nPress 2 for rear_enqeue\nPress 3 to quit" << endl;
				cin >> choice;
				switch (choice)
				{
				case 1: {
					front_enqueue();
					break;
				}
				case 2: {
					rear_enqueue();
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
		case 2: {
			do
			{
				cout << "\n\nPress 1 to for front_dequeue\nPress 2 for rear_deqeue\nPress 3 to quit" << endl;
				cin >> choice;
				switch (choice)
				{
				case 1: {
					front_deque();
					break;
				}
				case 2: {
					rear_deque();
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
			if (isEmpty())
			{
				cout << "Queue is Empty" << endl;
			}
			else {
				cout << "Queue is not empty" << endl;
			}
			break;
		}
		case 4: {
			if (isFull())
			{
				cout << "Queue is FULL" << endl;
			}
			else {
				cout << "Queue is not full" << endl;
			}
			break;
		}
		case 5: {
			display();
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