#include<iostream>
using namespace std;
struct deque
{
	int data;
	deque *lptr;
	deque *rptr;
};

deque *first = NULL;
deque *Prev = NULL;
deque *last = NULL;

bool isEmpty() {
	if (first == NULL) {
		return true;
	}
	else {
		return false;
	}
}

void enqueue() {
	int num = 0;
	deque *newNode = new deque();
	cout << "Press 1 to enqueue from the front" << endl;
	cout << "Press 2 to enqueue from the rear" << endl;
	cin >> num;
	cout << "Enter number: ";
	cin >> newNode->data;
	
	if (num == 1) {
		if (first == NULL) {
			last = Prev = first = newNode;
		}
		else {
			deque*temp = first;
			while (temp->lptr!=NULL)
			{
				temp = temp->lptr;
			}
			temp->lptr = newNode;
			Prev = temp;
			first = temp = temp->lptr;
			temp->rptr = Prev;
		}
	}
	else if (num == 2) {
		if (first == NULL) {
			last = Prev = first = newNode;
		}
		else {
			deque*temp = first;
			while (temp->rptr != NULL)
			{

				temp = temp->rptr;
			}
			temp->rptr = newNode;
			Prev = temp;
			last = temp = temp->rptr;
			temp->lptr = Prev;
		}
	}
	
	
}

void deqeue() {
	int num = 0;
	if (isEmpty()) {
		cout << "deque is empty" << endl;
	}
	else {
		cout << "Press 1 to delete from the front" << endl;
		cout << "Press 2 to delete from the rear" << endl;
		cin >> num;
		if (first == last) {
			first = last = NULL;
		}
		else {
			if (num == 1) {
				first = first->rptr;
				first->lptr = NULL;

			}
			else if (num == 2) {
				last = last->lptr;
				last->rptr = NULL;
			}
		}
	}

	
}

void display() {
	if (first == NULL) {
		cout << "Deque is empty" << endl;
	}
	else {
		deque*temp = first;
		while (temp)
		{
			cout << temp->data << " ";
			temp = temp->rptr;
		}
		cout << endl;
	}

}
void  peek() {
	if (first == NULL) {
		cout << "Deque is empty" << endl;
	}
	else {
		cout <<"Last: "<< first->data << endl;
		cout << "Last: " << last->data << endl;
	}
}

void mainMenu() {
	cout << "Press 1 to enqueue\nPress 2 to deqeue\npress 3 to display\nPress 4 to peek" << endl;
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
			enqueue();
			break;
		case 2:
			deqeue();
			break;
		case 3:
			display();
			break;
		case 4:
			peek();
			break;
		default:
			cout << "Wrong input" << endl;
			break;
		}
		cout << "Press 1 to continue\nPress 2 to quit" << endl;
		cin >> num;

	} while (num==1);
	
}
