#include<iostream>
#include<string>
using namespace std;
#define Max 10

struct Stack {
	char arr[Max];
	int top ;
};
Stack st;

bool isFull(){
	if (st.top == Max) {
		return true;
	}
	else {
		return false;
	} 

}

bool isEmpty() {
	if (st.top == -1) {
		return true;
	}
	else {
		return false;
	}

}

void Push(char &num) {

	st.top++;
	st.arr[st.top] = num;
}

char pop() {
	char temp = st.arr[st.top];
	st.top--;
	
	return temp;
}

void peek() {
	if (isEmpty()) {
		cout << "Stack is empty" << endl;
		
	}
	else {
		cout<<st.arr[st.top]<<endl;
	}
}

void display() {
	for (int i = st.top; i >=0 ; i--)
	{
		cout << "     |"<< st.arr[i] <<"|     "<< endl;
	}
}

bool isOperator(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/') {
		return true;
	}
	else {
		return false;
	}
}

bool isOperande(char &c) {
	if (c >= 'a' && c <= 'z' || c >= 'A'&&c <= 'Z') {
		return true;
	}
	else {
		return false;
	}
}
int precedence(char &c) {
	if (c == '^') {
		return 3;
	}
	else if (c == '/' || c == '*') {
		return 2;
	}
	else if (c == '+' || c == '-') {
		return 1;
	}
	else {
		return 0;
	}

}


string infixToPostfix(string infix) {
	string postFix;
	bool found = false;
	for (int i = 0; i < infix.length(); i++) {
		if (isOperande(infix[i])) {
			postFix += infix[i];
		}
		else if (infix[i] == '(') {
			Push(infix[i]);
		}
		else if ((isOperator(infix[i]) && isEmpty()) || (isOperator(infix[i]) && st.arr[st.top]=='(')) {
			Push(infix[i]);
		}
		else if (infix[i] == ')') {
			while (st.arr[st.top]!='(' &&isOperator(st.arr[st.top]))
			{
				postFix += pop();
				
			}
		}
		else if (isOperator(infix[i]) && isOperator(st.arr[st.top])) {
			int j = i;

			do
			{
				if (precedence(infix[j]) <= precedence(st.arr[st.top])) {
					postFix += pop();
					Push(infix[j]);
					j++;
				}
				else {
					Push(infix[i]);
					j++;
				}
			} while ((st.arr[st.top] != '(' ) && (isOperator(infix[j]) && isOperator(st.arr[st.top])));
		}
		else if (!isOperator(infix[i]) && !isOperande(infix[i]) &&infix[i]!='('&&infix[i]!=')') {
			cout << "Wrong input was given" << endl;
			found = true;
			break;
		}
		
	}
	

	while (!isEmpty()) {
		if (st.arr[st.top] == '(' || st.arr[st.top] == ')') {
			pop();
		}
		else { 
			postFix += pop();
		}
	}
	
	if (found == true) {
		for (int i = 0; i < postFix.length(); i++) {
			postFix[i] = '\0';
		}
	}
	
	return postFix;
}

string infixToPrefix(string infix) {
	string postFix;
	int i = 0;
	while (infix[i]!=NULL)
	{
		i++;
	}
	return postFix;
}

void mainMenu() {
	cout << "<------------------Stack--------------->" << endl;
	cout << "Press 1 for operation\nPress 2 for coversetion\nPress 3 to exit" << endl;
}

int main() {
	string infix;
	st.top = -1;
	int ask = 0;
	char num;
	
	do
	{
		mainMenu();
		cin >> ask;
		int k = 0;

		switch (ask)
		{
		case 1:
			do
			{
				cout << "Press 1 to push\nPress 2 to pop\nPress 3 to check if the stack is empty or full" <<
					"\nPress 4 to peek\nPress 5 to display the stack\nPress 6 to exit to main menu" << endl;
				cin >> ask;
				switch (ask)
				{
				case 1: {
					do
					{
						if (isFull())
						{
							cout << "OverFlow" << endl;
						}
						else {
							cout << "Plz only enter a single character" << endl;

							cout << "Enter the number you want to push: ";
							cin.ignore();
							cin >> num;
							Push(num);
						}

						cout << "Press 1 to push more\nPress 2 to stop" << endl;
						cin >> ask;
					} while (ask != 2);
					break;
				case 2:
					do
					{
						if (isEmpty()) {
							cout << "UnderFlow" << endl;
						}
						else {
							cout << "The number popped is: " << pop() << endl;

							cout << "Press 1 to pop more\nPress 2 to stop" << endl;
							cin >> ask;
						}

					} while (ask != 2);

				}
						break;

				case 3:
					if (isEmpty())
					{
						cout << "UnderFlow" << endl;
					}
					else if (isFull()) {
						cout << "OverFlow" << endl;
					}
					else {
						cout << "Stack is neither full nor empty" << endl;
					}
					break;
				case 4:
					peek();
					break;
				case 5:

					display();
					break;
				case 6:
					break;
				default:
					break;
				}
			} while (ask != 6);
			break;
		case 2:
			cout << "Enter infix expression: ";
			cin.ignore();
			getline(cin, infix);
			cout << "Infix Expression: " << infix << endl;
			cout << infixToPostfix(infix)<<endl;

			break;
		case 3:
			break;
		default:
			break;
		}

	} while (ask != 3);
}