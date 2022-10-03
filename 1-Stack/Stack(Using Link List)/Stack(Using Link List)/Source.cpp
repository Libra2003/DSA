#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};
Node* top = NULL;


bool isEmpty() {
	if (top == NULL) {
 		return true;
	}
	else {
		return false;
	}
}

bool isFull() {
	Node* newNode = new Node();
	if (newNode == NULL) {
		return true;
	}
	else {
		return false;
	}
}

Node* push() {
	if (isFull()) {
		cout << "Stack overflowed" << endl;
	}
	else {
		Node* newNode = new Node();
		cout << "Push Number: ";
		cin >> newNode->data;
		if (isEmpty()) {
			top = newNode;
		}
		else {
			newNode->next = top;
			top = newNode;
		}
		return top;
	}
	
}

Node* pop() {
	if (isEmpty()) {
		cout << "Stack Underflow" << endl;
	}
	else {
		top = top->next;
		return top;
	}
	
}


int peek() {
	if (isEmpty()) {
		cout << "Stack underflow" << endl;
	}
	else {
		return top->data;
	}

}

int stackBottom() {
	if (isEmpty()) {
		cout << "Stack underflow" << endl;
	}
	else {
		Node* temp = top;
		while (temp->next!=NULL)
		{
			temp = temp->next;
		}
		return temp->data;
	}
}

void display() {
	if (isEmpty()) {
		cout << "stack Underflow" << endl;
	}
	else {
		Node* temp = top;
		while (temp) {
			cout << temp->data << endl;
			temp = temp->next;
		}
	
	}
}

int main() {
	int choice = 0;
	int value = 0;
	do
	{
		cout << "Press 1 to Push\nPress 2 to pop\nPress 3 for isFull\nPress 4 for isEmpty\nPress 5 to peek\nPress 6 to display" <<
			"\nPress 7 to see the stack bottom" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: {
			push();
			break;
		}
		case 2: {
			pop();
			break;
		}
		case 3: {
			if (isFull()) {
				cout << "Stack is FULL" << endl;
			}
			else {
				cout << "Stack is not full" << endl;
			}
			break;
		}
		case 4: {
			if (isEmpty()) {
				cout << "Stack is empty" << endl;
			}
			else {
				cout << "Stack is not empty" << endl;
			}
			break;
		}
		case 5: {
			if (isEmpty()) {
				cout << "Stack is empty" << endl;
			}
			else {
				cout << "peek: " << peek() << endl;
			}
			break;
		}
		case 6: {
			display();
			break;
		}

		case 7: {
			cout << "Bottom: " << stackBottom() << endl;
			break;
		}
		default:
			cout << "Plz enter the correct input" << endl;
			break;
		}
		cout << "Press 1 to continue\nPress 2 to quit" << endl;
		cin >> choice;
	} while (choice == 1);
}