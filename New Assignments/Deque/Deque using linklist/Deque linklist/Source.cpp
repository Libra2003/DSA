#include<iostream>
using namespace std;

#define Max 10

struct Deque {
	int data, Count;
	Deque *next;
};
Deque *front = NULL;
Deque *rear = NULL;
Deque de;

bool isEmpty() {
	if (front==NULL&&rear==NULL) {
		return true;
	}
	else {
		return false;
	}
}

void pushFront() {
	int num = 0;
	do
	{
		Deque*newNode = new Deque();
		cout << "Enter Number: ";
		cin >> newNode->data;
		if (isEmpty()) {
			rear = front = newNode;
		}
		else {
			newNode->next = front;
			front = newNode;
			cout << "Press 1 to push more\nPress 2 to stop" << endl;
			cin >> num;
			
		}

	} while (num==1);

	
	
}

void pushRear() {
	int num = 0;
	do
	{
		Deque *newNode = new Deque();
		cout << "Enter number: ";
		cin >> newNode->data;
		if (isEmpty()) {
			front = rear = newNode;
		}
		else {
			Deque*temp = front;
			while (temp->next!=NULL)
			{
				temp = temp->next;
			}
			rear = newNode;
			temp->next = rear;

			cout << "Press 1 to push more\nPress 2 to stop" << endl;
			cin >> num;
		}

		
	} while (num==1);
}

void popFront() {
	Deque *newNode = new Deque();
	newNode = front;
		front = front->next;
		cout << "Deleted data: " << newNode->data << endl;

}

void popRear() {
	Deque *temp = front;
	Deque *temp2 = front;
	while (temp->next!=NULL)
	{
		temp2 = temp;
		temp = temp->next;
	}
	cout << "Deleted data: " << temp->data << endl;
	temp2->next = NULL;
	rear = temp2;
	
}

void display() {
	Deque *temp = front;
	while (temp)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

void peek() {
	cout << "Value at the front is: " << front->data << endl;

}

void mainMenu() {
	cout << "<------------------Deque--------------->" << endl;

	cout << "Press 1 to push" << endl;
	cout << "Press 2 to pop" << endl;
	cout << "Press 3 to display" << endl;
	cout << "Press 4 to peek" << endl;
}
int main() {
	de.Count = 0;
	int num = 0;
	do
	{
		mainMenu();
		cin >> num;
		switch (num)
		{
		case 1:
			do
			{
					cout << "Press 1 to pushFront\nPress 2 to pushRear\nPress 3 to exit" << endl;
					cin >> num;
					switch (num)
					{
					case 1:
						pushFront();
						break;
					case 2:
						pushRear();
						break;
					case 3:
						break;
					default:
						cout << "Wrong input" << endl;
						break;
					}
			} while (num != 3);
		
			
			break;
		case 2:
			do
			{
				cout << "Press 1 to popFront\nPress 2 to popRear\nPress 3 to exit" << endl;
				cin >> num;
				if (isEmpty()) {
					cout << "Deque is empty" << endl;
				}
				else {
					switch (num)
					{
					case 1:
						
							popFront();
						
						break;
					case 2:
					
							if (front->next == NULL) {
								popFront();
							}
							else {
								popRear();

							}
						

						break;
					case 3:
						break;
					default:
						cout << "Wrong input" << endl;
						break;
					}
				}
			} while (num != 3);
			break;
		case 3:
			if (isEmpty()) {
				cout << "Deque is empty" << endl;
			}
			else {
				display();
			}
			break;
		case 4:
			if (isEmpty()) {
				cout << "Deque is empty" << endl;
			}
			else {
				peek();
			}
			break;
		default:
			cout << "Wrong input" << endl;

			break;
		}

	} while (num!=5);
}