#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

	Node* front = NULL;
	Node* rear = NULL;

bool isEmpty() {
	if (front == NULL) {
		return true;
	}
	else {
		return false;
	}
}
	
void enqueue() {
	Node*newNode = new Node();
	cout << "Enter number: ";
	cin >> newNode->data;
	if (isEmpty()) {
		rear = front = newNode;
	}
	else {
		Node*temp = front;
		while (temp->next!=NULL &&temp!=rear)
		{
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->next = front;
		rear = newNode;
	}
}
void dequeue() {
	if (front->next == NULL) {
		front = NULL;
	}
	else {
		front = front->next;
		rear->next = front;
	}
}

void display() {
	Node*temp = front;
	while (temp!=rear)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << rear->data << " ";
	cout << endl;
}

void peek() {
	cout << "Front: " << front->data << endl;
}

void mainMenu()
{
			int option, d;

			for (int i = 0; i >= 0; i++)
			{
				cout << endl;
				cout << "Press '1' to Enqueue an element.\nPress '2' to Dequeue an element.\nPress '3' to peek the data on top.\nPress '4' to display all elements.\nPress '0' to exit to main menu." << endl;
				cin >> option;
				switch (option)
				{
				case 1:
					system("cls");

					enqueue();
					break;
				case 2:
					system("cls");
					dequeue();
					break;
				case 3:
					system("cls");
					peek();
					break;
				case 4:
					system("cls");
					display();
					break;
				case 0:
					exit(1);
				default:
					system("cls");
					cout << "Invalid input, try again\n\n";
				}
			}
}



int main()
{

	int d = 0;

	mainMenu();

	return 0;
}