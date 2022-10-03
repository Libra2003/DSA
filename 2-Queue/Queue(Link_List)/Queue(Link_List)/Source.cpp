#include<iostream>
using namespace std;

struct queue {
	queue* next;
	int data;
};
queue* head = NULL;
queue* front = NULL;
bool isEmpty() {
	if (front == NULL) {
		return true;
	}
	else {
		return false;
	}
}

//if Heap memmory is full true will be returned
bool isFULL() {
	queue* head = new queue();
	if (head == NULL) {
		return true;
	}
	else {
		return false;
	}
}

queue* enqueue() {
	if (isFULL()) {
		cout << "Memmory is FULL" << endl;
	}
	else {
		queue* newNode = new queue();
		cout << "\nEnter number: ";
		cin >> newNode->data;
		if (isEmpty()) {
			front = head = newNode;
		}
		else {
			queue* temp = head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = newNode;
		}
	}
	return head;
}

queue *dequeue() {
	if (isEmpty())
	{
		cout << "Queue is empty" << endl;
	}
	else {
		front = front->next;
	}
	return front;
}

void display() {
	queue* temp = front;
	while (temp!=NULL)
	{
		cout << temp->data << endl;
		temp = temp->next;
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
			enqueue();
			break;
		}
		case 2: {
			dequeue();
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
			if (isFULL())
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
		default:
			cout << "Plz give the right input" << endl;
			break;
		}

	} while (choice != 0);

}