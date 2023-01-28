#include<iostream>
using namespace std;
#define Max 10

struct queue {
	int data, Count;
	queue *next;
};

queue *front = NULL;
queue *rear = NULL;
queue qu;

bool isEmpty() {
	
	if (front==NULL) {
		return true;
	}
	else {
		return false;
	}

}

void enqueue(int num) {
	do
	{
		queue *newNode = new queue();
		cout << "Enter entry: ";
		cin >> newNode->data;
		if (isEmpty()) {
			rear  = newNode;
			front = rear;
		}
		else {
			queue *temp = front;
			while (temp->next!=NULL)
			{
				temp = temp->next;
			}
			temp->next = newNode;
			rear = newNode;

		}
		
		cout << "Press 1 to queue more\nPress 2 to stop" << endl;
		cin >> num;
		
	} while (num==1);
	

}
int dequeue() {
	int num = 0;
		num = front->data;
		front = front->next;
	return num;
}

void peek() {
	cout <<"Data at the end is: "<< rear->data << endl;
	cout <<"Data at the start is: "<< front->data << endl;
}


void display() {
	queue *temp = front;
	
	while (temp)
	{
		cout << temp->data<<" " ;
		temp = temp->next;
	}
	cout << endl;
}
void mainMenu() {
	cout << "<------------------Queue--------------->" << endl;

	cout << "Press 1 to enqueue" << endl;
	cout << "Press 2 to dequeue" << endl;
	cout << "Press 3 display" << endl;
	cout << "Press 4 to peek" << endl;
	cout << "Press 5 to see if the queue is full or not" << endl;
	cout << "Press 6 exit" << endl;
}
int main() {
	front = rear =  NULL;
	int num = 0;
	do
	{
		mainMenu();
		
		cin >> num;
		switch (num)
		{
		case 1:
			enqueue(num);
		break;
		case 2:
			if (front == NULL) {
				cout << "Queue is empty" << endl;
			}
			else {
				cout << dequeue() << endl;

			}
			break;
		case 3:
			if (front == NULL) {
				cout << "Queue is empty" << endl;
			}
			else {
				display();
			}
			break;
		case 4:
			if (front == NULL) {
				cout << "Queue is empty" << endl;
			}
			else {
				peek();

			}

			break;
		case 5:
			if (qu.Count == Max) {
				cout << "queue is full" << endl;
			}
			else if (front == NULL) {
				cout << "queue is empty" << endl;
			}
			else {
				cout << "queue is neither empty nor full" << endl;
			}
			break;
		case 6:
			break;
		default:
			cout << "Wrong input try again" << endl;
			break;
		}

	} while (num!=6);
}