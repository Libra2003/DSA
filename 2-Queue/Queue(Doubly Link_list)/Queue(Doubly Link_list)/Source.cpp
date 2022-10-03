#include<iostream>
using namespace std;

struct queue {
	queue* r;
	queue* l;
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
			while (temp->r != NULL) {
				temp = temp->r;
			}
			temp->r = newNode;
			newNode->l = temp;
		}
	}
	return head;
}


queue* dequeue() {
	if (isEmpty())
	{
		cout << "Queue is empty" << endl;
	}
	else {
		front = front->r;
		front->l = NULL;
		if (front->r==NULL)
		{
			front = NULL;
		}
	}
	return front;
}

void display() {
	queue* temp = front;
	cout << "Forward" << endl;
	if (front==NULL)
	{
		cout << "Queue is empty" << endl;
	}
	else {
		while (temp->r != NULL)
		{
			cout << temp->data << endl;
			temp = temp->r;
		}
		queue* temp2 = temp;
		cout << temp->data << endl;
		cout << "Reverse" << endl;
		while (temp2 != NULL)
		{
			cout << temp2->data << endl;
			temp2 = temp2->l;
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