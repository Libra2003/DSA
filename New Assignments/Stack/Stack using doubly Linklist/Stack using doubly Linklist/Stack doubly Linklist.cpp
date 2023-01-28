#include<iostream>
using namespace std;
#define Max 6
struct Stack {
	int data;
	Stack *lptr, *rptr;
};

Stack *top;
Stack *last;

bool is_Empty() {
	if (top == NULL) {
		return true;
	}
	else {
		return false;
	}
}

void push() {
	Stack *newNode = new Stack();
	cout << "Enter Number: ";
	cin >> newNode->data;
	if (is_Empty()) {
		last = top = newNode;

	}
	else {
		Stack *temp = top;
		top = newNode;
		top->rptr = temp;
		temp->lptr = top;
	}
}

int pop() {

	int value = top->data;
	if (top->rptr == NULL) {
		top = NULL;
	}
	else {
		top = top->rptr;
		top->lptr = NULL;
	}
	return value;
}

void peek() {
	if (is_Empty()) {
		cout << "Stack is empty" << endl;
	}
	else {
		cout << "top: " << top->data << endl;
	}
}


void display() {
	if (top == NULL) {
		cout << "Stack is empty" << endl;
	}
	else {
		Stack *temp = top;
		while (temp)
		{
			cout << temp->data << endl;
			temp = temp->rptr;
		}
		cout << endl;
		Stack *temp2 = last;
		cout << "reverse" << endl;
		while (temp2)
		{
			cout << temp2->data << endl;
			temp2 = temp2->lptr;
		}
		cout << endl;
	}
}

void mainMenu() {
	cout << "<------------------Stack--------------->" << endl;
	cout << "Press 1 to push" << endl;
	cout << "Press 2 to pop" << endl;
	cout << "Press 3 to display" << endl;
	cout << "Press 4 to peek" << endl;
	cout << "Press 5 to see if the stack is full or not" << endl;
	cout << "Press 6 to exit" << endl;

}

int main() {
	int num = 0;
	do
	{
		mainMenu();
		cin >> num;
		switch (num)
		{
		case 1:
		
				push();
			
			break;
		case 2:
			if (top == NULL) {
				cout << "Stack is empty" << endl;
			}
			else {
				cout << "Value popped: " << pop();
			}
			break;
		case 3:
			display();
			break;
		case 4:
			peek();
			break;

		case 5:
			if (top == NULL) {
				cout << "Stack is empty" << endl;
			}
			else {
				cout << "Stack is not empty" << endl;
			}
			break;
		case 6:
			break;
		default:
			cout << "Wrong input" << endl;
			break;
		}

	} while (num != 6);
}
