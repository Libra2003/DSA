#include<iostream>
#include<string>
using namespace std;


const int SIZE = 10;

class Stack
{
private:
public:
	char ch[SIZE];

	int top;
	Stack();
	void push(char&);
	char pop();
	bool isEmpty();
	bool isFull();
	char peek();
	void displayItems();

};
Stack::Stack() {
	top = -1;
}
bool Stack::isEmpty() {
	if (top == -1)
		return true;
	else
		return false;
}
bool Stack::isFull() {
	if (top == (SIZE - 1))
		return true;
	else
		return false;
}
void Stack::push(char& n) {

	if (isFull()) {
		cout << "Stack Overflow!";
	}
	else {
		++top;
		ch[top] = n;
	}
}
char Stack::pop()
{
	char temp;
	if (isEmpty())
	{
		cout << "Stack is empty\n";
		return 0;
	}
	else {
		temp = ch[top];
		--top;
		return temp;
	}
}
char Stack::peek() {
	if (isEmpty() == 1) {
		cout << "stack is empty";
		return -1;
	}
	else {
		return ch[top];
	}
}
void Stack::displayItems() {
	if (isEmpty()) {
		cout << "Stack is Empty.\n";
	}
	else {
		int i;
		cout << "STACK is: ";
		for (i = (top); i >= 0; i--) {
			cout << ch[i] << " ";
			cout << endl;
		}
	}
}

bool isOperand(char& infix) {
	if (infix >= 'A' && infix <= 'Z' || infix >= 'a' && infix <= 'z') {
		return true;
	}
	else {
		return false;
	}
}
bool isOperator(char infix) {
	if (infix == '+' || infix == '-' || infix == '*' || infix == '/' || infix == '^') {
		return true;
	}
	else {
		return false;
	}
}
int precedence(char& symbol)
{
	if (symbol == '^')
	{
		return(3);
	}
	else if (symbol == '*' || symbol == '/')
	{
		return(2);
	}
	else if (symbol == '+' || symbol == '-')
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

string infixToPostfix(string& infix) {
	Stack stk2;
	string postfix;
	char temp;
	int i = 0;
	while (infix[i] != NULL)
	{
		temp = infix[i];
		if (isOperand(temp)) {
			postfix += temp;
		}
		else if (temp == '(') {
			stk2.push(temp);
		}
		else if (isOperator(infix[i]) && stk2.isEmpty() || isOperator(temp) && stk2.peek() == '(') {
			stk2.push(temp);
		}
		else if (temp == ')') {
			while (stk2.ch[stk2.top] != '(' && isOperator(temp)) {
				
				postfix += stk2.pop();
				
				i++;
				temp = infix[i];
			}
		}
		else if (isOperator(infix[i]) && isOperator(stk2.ch[stk2.top])) {
			int j = i;
			do {
				char top = stk2.peek();
					if (precedence(infix[j]) <= precedence(top)) {
						postfix += stk2.pop();
						stk2.push(infix[j]);
						j++;
					}
					else if (precedence(infix[j]) > precedence(top)) {
						stk2.push(temp);
						j++;
					}
				
				
			} while (infix[j] != '(' &&(isOperator(infix[j]) && isOperator(stk2.ch[stk2.top])));
		}
		i++;
	}

	while (!stk2.isEmpty()) {
		if (stk2.ch[stk2.top]=='('|| stk2.ch[stk2.top] == ')y') {
			stk2.pop();
		}
		else {
			postfix += stk2.pop();
		}
	}
	return postfix;
}

int main()
{
	Stack stk;
	int choice;
	char n;
	string infix;


	do
	{
		cout << endl;
		cout << "0 - Exit." << endl;
		cout << "1 - Push Item." << endl;
		cout << "2 - Pop Item." << endl;
		cout << "3 - Peek." << endl;
		cout << "4 - Display STACK." << endl;
		cout << "5 - Convert Infix To Postfix." << endl;
		cout << "Enter your choice: " << endl;
		cin >> choice;

		switch (choice)
		{
		case 0:
			break;

		case 1:
			cout << "Enter item to insert: ";
			cin >> n;
			stk.push(n);
			if (!stk.isFull()) {
				cout << n << " is pushed.\n";
			}
			break;

		case 2:

			if (stk.isEmpty() == false) {
				cout << stk.pop() << " is popped." << endl;
			}
			break;

		case 3:
			cout << stk.peek();
			cout << endl;
			break;

		case 4:
			stk.displayItems();
			break;

		case 5:
			cout << "Enter the Expression.\n";
			cin >> infix;
			cout << infixToPostfix(infix);
			break;
		default:
			cout << "An Invalid choice." << endl;
		}
	} while (choice != 0);


	return 0;

}