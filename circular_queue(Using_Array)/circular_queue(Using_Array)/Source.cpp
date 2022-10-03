#include<iostream>
using namespace std;
#define Max 7
struct Node {
	int fr;
	int arr[Max];
	int re;
};

bool isEmpty(Node *head) {
	if (head->fr==head->re)
	{
		return true;
	}
	else {
		return false;
	}
}

bool isFull(Node* head) {
	if (((head->re+1)%Max==head->fr))
	{
		return true;
	}
	else {
		return false;
	}
}

void enqeue(Node* head) {
	if (isFull(head))
	{
		cout << "Queue is Full" << endl;
	}
	else {
		int num = 0;
		cout<< "Enqeue: ";
		cin >> num;	
		if (head->re == Max - 1) {
			head->re = 0;
		}
		
			head->re = (head->re + 1) % Max;
			head->arr[head->re] = num;
		
			
	}
}

int deque(Node* head) {
	if (isEmpty(head))
	{
		cout << "Queue is Empty" << endl;
	}
	else {
		head->arr[head->fr] = 0;
		head->fr++;
	}
	return head->fr;
}

void display(Node* head) {
	for (int i = 0; i < Max-1; i++)
	{
		cout << head->arr[i] << "-->";

	}
}

int main() {
	int choice = 0;
	Node* head = new Node();
	head->fr = 0;
	head->re = 0;

	do
	{
		cout << "\nPress 1 to enqueue\nPress 2 to deque\nPress 3 to check see if queue is empty or not\nPress 4 to see if queue is full or not " <<
			"\nPress 5 to display\nPress 0 to quit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 6: {
			exit(0);

		}
		case 1: {
			enqeue(head);
			break;
		}
		case 2: {
			deque(head);
			break;
		}
		case 3: {
			if (isEmpty(head))
			{
				cout << "Queue is Empty" << endl;
			}
			else {
				cout << "Queue is not empty" << endl;
			}
			break;
		}
		case 4: {
			if (isFull(head))
			{
				cout << "Queue is FULL" << endl;
			}
			else {
				cout << "Queue is not full" << endl;
			}
			break;
		}
		case 5: {
			display(head);
			break;
		}
		default:
			cout << "Plz give the right input" << endl;
			break;
		}

	} while (choice != 0);
}