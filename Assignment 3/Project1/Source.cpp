#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* start = NULL;

void create() {
	int limit;
	cout << "Enter how many numbers you want to enter: ";
	cin >> limit;
	for (int i = 0; i < limit; i++) {
		Node* newNode = new Node();
		if (start == NULL) {
			cout << "Enter Number " << i + 1 << ": ";
			cin >> newNode->data;
			start = newNode;
		}
		else {
			Node* temp = start;
			cout << "Enter Number " << i + 1 << ": ";
			cin >> newNode->data;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = newNode;
		}
	}

}

void display() {
	Node* temp = start;
	while (temp)
	{
		cout << temp->data << "-->";
		temp = temp->next;
	}

	cout << endl;

}

void search(int &Num) {
	Node* newNode = new Node();
	bool found = true;
	cout << "Enter the number you want to search: ";
	cin >> Num;
	int i = 1;
	Node* temp = start;
	while (temp)
	{
		if (temp->data == Num) {
	

			cout << "Number " << temp->data << " is found at " << i << endl;
			found = true;
			break;
		}
		else {
			found = false;
		}
		temp = temp->next;
		i++;
	}
	if (found == false) {
		cout << "Number not found" << endl;
	}
}
void insert_At_Start(int &num) {

	cout << "Enter the number you want to Insert: ";
	cin >> num;
	Node* newNode = new Node();
	newNode->data = num;
	if (start == NULL) {
		newNode->next = NULL;
		start = newNode;
	}
	else {
		newNode->next = start;
		start = newNode;
	}
}
void insert_At_Middle(int pos, int num) {
	Node* newNode = new Node();
	cout << "Enter posuton at which you want to insert: ";
	cin >> pos;
	cout << "Enter the number you want to insert: ";
	cin >> num;
	pos = pos - 2;
	newNode->data = num;
	newNode->next = NULL;
	int i = 0;
	if (start == NULL) {
		start = newNode;
		newNode->next = NULL;
	}
	else {
		Node*temp = start;
		while (temp) {
			if (i == pos) {
				newNode->next = temp->next;
				temp->next = newNode;
				break;

			}
			temp = temp->next;
			i++;
		}
	}
}
void insert_At_End(int &num) {
	Node* newNode = new Node();
	cout << "Enter Number you want to insert: ";
	cin >> num;
	newNode->data = num;
	newNode->next = NULL;
	if (start == NULL) {
		start = newNode;

	}
	else {
		Node* temp = start;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newNode;
	}
}
void Delete() {
	int num;
	Node* newNode = new Node();
	cout << "Enter the number you want to Delete: ";
	cin >> num;
	newNode->data = num;
	newNode->next = NULL;
	Node* temp = start;
	Node* temp1 = temp;
	int i = 1;
	while (temp)
	{
		if (temp->data == num) {
			if (i == 1) {
				start = start->next;
				break;
			}
			else {
				temp1->next = temp->next;
				cout << "Node successfully deleted" << endl;
				break;
			}


		}

		temp1 = temp;
		temp = temp->next;
		i++;

	}

}
void sort() {
	int swap;
	Node* temp = start;

	while (temp != NULL) {
		Node* temp1 = temp->next;
		while (temp1 != NULL)
		{
			if (temp->data > temp1->data) {
				swap = temp->data;
				temp->data = temp1->data;
				temp1->data = swap;

			}
			temp1 = temp1->next;
		}
		temp = temp->next;

	}



}

void menu() {
	cout << "Enter 1 To Create a list\nEnter 2 to Traverse the list\nEnter 3 to search the list" <<
		"\nEnter 4 to insert in the list\nEnter 5 to delete from the list\nEnter 6 to sort the list" << endl;
}
int main() {
	int num = 0;
	int pos = 0;
	int choice;

	do
	{
		menu();
		cin >> choice;

		switch (choice)
		{
		case 1: {
			create();
			break;
		}
		case 2: {
			display();
			break;
		}
		case 3: {
			search(num);
			break;
		}
		case 4: {
			cout << "Enter 1 to insert at start\nEnter 2 to insert at middle\nEnter 3 to insert at End" << endl;
			cin >> choice;
			switch (choice)
			{
			case 1: {
				insert_At_Start(num);
				display();
				break;
			}
			case 2: {
				insert_At_Middle(pos, num);
				break;
			}
			case 3: {
				insert_At_End(num);
				break;
			}
			default:
				break;
			}

		}
		case 5: {
			Delete();
			break;
		}
		case 6: {
			sort();
			break;
		}

		default:
			break;
		}

	} while (true);


}