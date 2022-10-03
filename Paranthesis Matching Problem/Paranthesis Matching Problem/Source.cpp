#include<iostream>
#include<string>
using namespace std;

struct Node {
	int Size;
	int top;
	int* arr;
};

void push(Node*ptr , char ent);
char pop(Node* ptr);
bool Matching(char one, char two) {
	if ((one == '(' && two == ')') || (one == '{' && two == '}') || (one == '[' && two == ']')) {
		return true;
	}
	else {
		return false;
	}
}

void check(Node*ptr, char exp[]) {
	char popped;
	
	for (int i = 0; i < 20; i++)
	{
		if (exp[i]=='('|| exp[i] == '['|| exp[i] == '{')
		{
			push(ptr, exp[i]);
		}
		else if(exp[i] == ')' || exp[i]=='}' || exp[i]==']') {
			popped = pop(ptr);
			ptr->top--;
			if (ptr->top == -1) {
				break;
			}
			if (Matching(exp[i],popped)){
				continue;
			}
			else {
				break;
			}
		}
				
	}
	if (ptr->top > 0) {
		cout << "Expression is not balanced" << endl;
	}
	else if (ptr->top < 0) {
		cout << "Stack is underflow" << endl;
	}
	else {
		cout << "Stack is balacnced" << endl;
	}
	
}

void push(Node*ptr , char ent) {
	ptr->top++;
	ptr->arr[ptr->top] = ent;

}

char pop(Node* ptr) {
	return ptr->arr[ptr->top];
}

int main() {
	Node* ptr = new Node();
	ptr->Size = 20;
	ptr->top = 0;
	ptr->arr = (int*)malloc(ptr->Size * sizeof(int));
	char exp[20];
	cout << "Enter Expression: ";
	cin >> exp;
	check(ptr , exp);
}