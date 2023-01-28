#include<iostream>
using namespace std;
#define Max 10
struct Stack{
	int data;
	Stack *next;
};
Stack *top = NULL;


bool isEmpty() {
	if (top == NULL) {
		return true;
	}
	else {
		return false;
	}
}

void push() {
	int num = 0;
	do
	{
		Stack *newNode = new Stack();
		cout << "Enter number: ";
		cin >> newNode->data;
		if (isEmpty()) {
			top = newNode;
		}
		else {
			Stack *temp = top;
			top = newNode;
			top->next = temp;
		}
	
		cout << "Press 1 to push again\nPress 2 to stop" << endl;
		cin >> num;
		

	} while (num==1);

}

void pop() {
	Stack *temp = top;
	
	if (isEmpty()) {
		cout << "Stack is empty" << endl;
	}
	else {
		top = top->next;
		temp = NULL;
		
	}
}

void display() {
	Stack *temp = top;
	if (isEmpty()) {
		cout << "Stack is empty" << endl;
	}
	else {
		while (temp)
		{
			cout << temp->data << endl;
			temp = temp->next;
		}
		
	}
}

void peek() {
	if (isEmpty()) {
		cout << "Stack is empty" << endl;
	}
	else {
		cout << "Value at the front is: " << top->data << endl;
		
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
			pop();
			break;
		case 3:
			display();
			break;
		case 4:
			peek();
			break;

		case 5:
			if (isEmpty()) {
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
		
	} while (num!=6);
}