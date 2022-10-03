#include<iostream>
#include<string>
using namespace std;
#define Max 10
struct Node {
	char arr[Max];
	int top;
};
Node stack;

bool isEmpty() {
	if (stack.top == -1) {
		return true;
	}
	else {
		return false;
	}
}

void push(char &value) {
	stack.top++;
	stack.arr[stack.top] = value;


}

char pop() {
	char temp = stack.arr[stack.top];
	stack.top--;
	return temp;
}

bool isOperande(char alpha) {
	if ((alpha >= 'a' && alpha <= 'z') || (alpha >= 'A' && alpha <= 'z')) {
		return true;
	}
	else {
		return false;
	}
}

bool isOperator(char oper) {
	if (oper == '+' || oper == '/' || oper == '*' || oper == '-') {
		return true;
	}
	else {
		return false;
	}
}

int precedence(char oper) {
	if (oper == '^') {
		return 3;
	}
	else if (oper == '/' || oper == '*') {
		return 2;
	}
	else if (oper == '+' || oper == '-') {
		return 1;
	}
	else {
		return 0;
	}
}

string infix_to_Postfix(string infix) {
	string postfix;
	int Size = infix.length();
	for (int i = 0; i < Size; i++)
	{
		if (isOperande(infix[i])) {
			postfix += infix[i];
		}
		else if (isOperator(infix[i])) {
			if (isEmpty()) {
				push(infix[i]);
			}
			else if (precedence(infix[i]) > precedence(stack.arr[stack.top])) {
				push(infix[i]);
			}
			else if ((precedence(infix[i]) == precedence(stack.arr[stack.top]))&&infix[i]=='^') {
				push(infix[i]);
			}
			else {
				while (!isEmpty()&&(precedence(infix[i])<=precedence(stack.arr[stack.top])))
				{
					postfix += pop();
				}
				push(infix[i]);
			}
		}
		else if (infix[i] == '(') {
			push(infix[i]);
		}
		else if (infix[i] == ')') {
			while (!isEmpty()&&stack.arr[stack.top]!='(')
			{
				postfix += pop();
			}
			if (stack.arr[stack.top]=='(') {
				pop();
			}
		}
	}
	while (!isEmpty())
	{
		postfix += pop();
	}

	return postfix;
}

string infix_to_Prefix(string infix) {
	string prefix;
	reverse(infix.begin(), infix.end());
	for (int i = 0; i < infix.length(); i++)
	{
		if (infix[i] == '(') {
			infix[i] = ')';
		}
		else if (infix[i] == ')') {
			infix[i] = '(';
		}
	}
	for (int i = 0; i < infix.length(); i++)
	{
		if (isOperande(infix[i]))
		{
			prefix += infix[i];
		}
		else if (isOperator(infix[i])) {
			if (isEmpty())
			{
				push(infix[i]);
			}
			else if (precedence(infix[i]) > precedence(stack.arr[stack.top])) {
				push(infix[i]);
			}
			else if (precedence(infix[i]) == precedence(stack.arr[stack.top]) && infix[i] == '^') {
				prefix += pop();
			}
			else if (precedence(infix[i]) == precedence(stack.arr[stack.top])) {
				push(infix[i]);
			}
			else if (precedence(infix[i]) < precedence(stack.arr[stack.top])) {
			
					while (!isEmpty() && precedence(infix[i]) < precedence(stack.arr[stack.top]))
					{
						prefix += pop();
					}
					push(infix[i]);				
				
			}
		}
		else if (infix[i] == '(') {
			push(infix[i]);
		}
		else if (infix[i] == ')') {
			while (!isEmpty()&&stack.arr[stack.top]!='(')
			{
				prefix += pop();
			}
			if (stack.arr[stack.top] == '(') {
				pop();
			}
		}
	}
	while (!isEmpty())
	{
		prefix += pop();
	}
	reverse(prefix.begin(), prefix.end());
	return prefix;
}

int main() {
	stack.top = -1;
	string infix;
	cout << "Enter Expression: ";
	cin >> infix;
	cout << infix_to_Postfix(infix) << endl;
	cout << infix_to_Prefix(infix) << endl;
}