#include<iostream>
using namespace std;

struct stack {
	int Size;
	int top;
	int* arr;
};

bool isFull(struct stack* ptr) {
	if (ptr->top == ptr->Size - 1) {
		return true;
	}
	else {
		return false;
	}
}

bool isEmpty( stack* ptr) {
	if (ptr->top == -1) {
		return true;
	}
	else {
		return false;
	}
}

void push( stack* ptr, int value) {
	if (isFull(ptr)) {
		cout << "Stack is full" << endl;
	}
	else {
		cout << "Enter number: ";
		cin >> value;
		ptr->top++;
		ptr->arr[ptr->top] = value;
	}
}

int pop(stack *ptr) {
	if (isEmpty(ptr)) {
		cout << "Stack is empty" << endl;
	}
	else {
		ptr->arr[ptr->top] = 0;
		ptr->top--;
	}
	return ptr->top;
}

int peek(stack* ptr) {
	if (isEmpty(ptr)) {
		cout << "Stack is empty" << endl;
	}
	else {
		return ptr->arr[ptr->top];

	}
}

void display(stack*ptr) {
	int limit = ptr->top;
	while (limit!=-1)
	{
		cout << ptr->arr[limit] << endl;
		limit--;
	}
}

int stackTop(stack* ptr) {
	if (isEmpty(ptr)) {
		cout << "Stack is empty" << endl;
	}
	else {
		return ptr->arr[ptr->top];
	}
}
int stackBottom(stack* ptr) {
	if (isEmpty(ptr)) {
		cout << "Stack is empty" << endl;
	}
	else {
		return ptr->arr[0];
	}
}

int main() {
	stack *newNode = new stack();
	newNode->top = -1;
	newNode->Size = 5;

	newNode->arr = (int*)malloc(newNode->Size * sizeof(int));

	int choice = 0;
	int value = 0;
	do
	{
		cout << "Press 1 to Push\nPress 2 to pop\nPress 3 for isFull\nPress 4 for isEmpty\nPress 5 to peek\nPress 6 to display"<<
			"\nPress 7 to see the stack bottom" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: {
			push(newNode, value);
			break;
		}
		case 2: {
			pop(newNode);
			break;
		}
		case 3: {
			if (isFull(newNode)) {
				cout << "Stack is FULL" << endl;
			}
			else {
				cout << "Stack is not full" << endl;
			}
			break;
		}
		case 4: {
			if (isEmpty(newNode)) {
				cout << "Stack is empty" << endl;
			}
			else {
				cout << "Stack is not empty" << endl;
			}
			break;
		}
		case 5: {
			if (isEmpty(newNode)) {
				cout << "Stack is empty" << endl;
			}
			else {
				cout <<"peek: "<< peek(newNode) << endl;
			}
			break;
		}
		case 6: {
			display(newNode);
			break;
		}	
		case 7: {
			cout<<"Top: "<< stackBottom(newNode)<<endl;
			break;
		}
		default:
			cout << "Plz enter the correct input" << endl;
			break;
		}
		cout << "Press 1 to continue\nPress to quit" << endl;
		cin >> choice;
	} while (choice==1);
}