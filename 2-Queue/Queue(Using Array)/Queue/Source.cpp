#include<iostream>
using namespace std;
#define Max 10
struct queue {
	int f;
	int r;
	int arr[Max];
};

bool isEmpty(queue *ptr) {
	if (ptr->f == ptr->r) {
		return true;
	}
	else {
		return false;
	}
}
bool isFull(queue*ptr) {
	if (ptr->f == -1 && ptr->r == (Max - 1)) {
		return true;
	}
	else {
		return false;
	}
}

void enqueue(queue* ptr) {
	int num = 0;
	if (isFull(ptr))
	{
		cout << "Queue is full" << endl;
	}
	else {
		cout << "Enter Number: ";
		cin >> num;
		ptr->r++;
		ptr->arr[ptr->r] = num;
	}
}

int dequeue(queue*ptr) {
	int n = -1;
	if (isEmpty(ptr)) {
		cout << "Stack is Empty" << endl;
	}
	else {
		ptr->f++;
		n = ptr->arr[ptr->f];
	}
	return ptr->f;
}

void display(queue *ptr) {
	if (isEmpty(ptr)) {
		cout << "Queue is empty" << endl;
	}
	else {
		for (int i = ptr->f; i <= ptr->r; i++)
		{
			cout << ptr->arr[i] << endl;
		}
			
	}
}



int main() {
	int choice = 0;
	queue *ptr = new queue();
	ptr->f = -1;
	ptr->r = -1;

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
			enqueue(ptr);
			break;
		}
		case 2: {
			dequeue(ptr);
			break;
		}
		case 3: {
			if (isEmpty(ptr))
			{
				cout << "Queue is Empty" << endl;
			}
			else {
				cout << "Queue is not empty" << endl;
			}
			break;
		}
		case 4: {
			if (isFull(ptr))
			{
				cout << "Queue is FULL" << endl;
			}
			else {
				cout << "Queue is not full" << endl;
			}
			break;
		}
		case 5: {
			display(ptr);
			break;
		}
		default:
			cout << "Plz give the right input" << endl;
			break;
		}

	} while (choice!=0);

}