#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* rptr;
	Node* lptr;
};
Node* head = NULL;

void create() {
	Node* newNode = new Node();
	int num = 0;
	cout << "Enter Number: ";
	cin >> newNode->data;

	if (head == NULL) {
		head = newNode;

	}
	else {
		Node* temp = head;
		while (temp->rptr != NULL)
		{
			temp = temp->rptr;
		}
		temp->rptr = newNode;
		newNode->lptr = temp;
	}

	cout << "\nPress 1 to enter more\nPress 2 to for main menu " << endl;
	cin >> num;
	if (num == 1) {
		create();
	}


}

struct Node* insert_At_Start(struct Node* newNode, int data) {

	if (head == NULL) {
		head = newNode;
	}
	else {
		newNode->rptr = head;
		head->lptr = newNode;
		head = newNode;
	}
	return head;
}

struct Node* insert_in_Middle(struct Node* newNode, int data) {
	int num = 0;

	Node* temp = head;
	Node* Prev = NULL;
	if (temp == NULL) {
		cout << "Link list hasn't been created yet " << endl;
		return temp;
	}
	cout << "Enter the number afther which you want to insert: ";
	cin >> num;
	while (temp != NULL)
	{

		if (num == Prev->data) {
			cout << "Enter Number: ";
			cin >> newNode->data;
			if (Prev == NULL) {
				temp = NULL;
			}

			else if (Prev->rptr == NULL) {
				Prev->rptr = newNode;
				newNode->lptr = Prev;
			}
			else {
				Prev->rptr = newNode;
				newNode->lptr = Prev;
				newNode->rptr = temp;
				temp->lptr = newNode;
			}
			break;
		}
		else if (temp->rptr == NULL && num == temp->data) {
			cout << "Enter Number: ";
			cin >> newNode->data;
			temp->rptr = newNode;
			temp = temp->rptr;
			break;
		}


		Prev = temp;
		temp = temp->rptr;

	}
	if (Prev == NULL) {

		cout << "Number not found " << endl;

	}
	return temp;

}

struct Node* insert_At_End(struct Node* newNode, int data) {
	Node* temp = head;
	while (temp->rptr != NULL)
	{
		temp = temp->rptr;
	}
	temp->rptr = newNode;
	newNode->lptr = temp;
	return temp;
}

struct Node* insert_At_Index(int index) {
	Node* newNode = new Node();
	Node* temp = head;
	Node* Prev = NULL;
	if (temp==NULL) {
		cout << "Link list has not been created yet" << endl;

	}
	else {
		for (int i = 0; i <= index; i++)
		{
			if (index == i) {
				cout << "Enter Number : ";
				cin >> newNode->data;
				if (Prev == NULL) {
					newNode->rptr = temp;
					temp->lptr = newNode;
					break;
				}
				else if (temp->rptr == NULL) {
					temp->rptr = newNode;
					newNode->lptr = temp;
					break;
				}
				else {
					Prev->rptr = newNode;
					newNode->lptr = Prev;
					newNode->rptr = temp;
					temp->lptr = newNode;
					break;
				}
				if (temp == NULL) {
					break;
				}

			}
			Prev = temp;
			temp = temp->rptr;

		}
	}

	return head;
}

struct Node* delete_From_Start() {
	Node* temp = head;
	Node* Prev = head;
	if (head == NULL) {
		cout << "Link list is NULL" << endl;
	}
	else {

		if (temp->rptr == NULL) {
			temp = NULL;
			return temp;
		}
		else {
			temp = temp->rptr;
			temp->lptr = NULL;
			head = temp;
			return head;
		}

	}

}

struct Node* delete_From_End() {
	if (head == NULL) {
		cout << "Link list doesn't exit" << endl;
		return NULL;
	}
	else {
		Node* temp = head;
		if (temp->rptr != NULL) {
			Node* Prev = temp;
			while (temp->rptr != NULL)
			{
				Prev = temp;
				temp = temp->rptr;
			}
			Prev->rptr = NULL;

		}
		else {
			temp = NULL;
		}
		return head;

	}
}

struct Node* delete_By_Value() {

	if (head == NULL) {
		cout << "Link list is empty" << endl;
	}
	else {
		Node* newNode = new Node();
		cout << "Enter Number: ";
		cin >> newNode->data;

		Node* temp = head;
		Node* Prev = NULL;
		while (temp != NULL)
		{
			if (temp->data == newNode->data) {
				if (Prev == NULL) {
					temp = NULL;
					break;
				}
				else {
					temp = temp->rptr;
					Prev->rptr = temp;
					temp->lptr = Prev;
					break;
				}

			}
			Prev = temp;
			temp = temp->rptr;

		}
	}
	return head;
}

struct Node* delete_By_Index(int Index) {
	Node* temp = head;
	Node* Prev = NULL;
	for (int i = 0;i <= Index;i++) {
		if (Index == i) {
			if (temp->rptr == NULL) {
				Prev->rptr = NULL;
			}
			else if (Prev == NULL) {
				temp = temp->rptr;
				temp->lptr = NULL;
			}
			else {
				temp = temp->rptr;
				Prev->rptr = temp;
				temp->lptr = Prev;
				head = Prev;
				return head;
			}
		}
	
		Prev = temp;
		temp = temp->rptr;
	}

}

void display() {
	cout << endl;
	Node* temp = head;
	while (temp != NULL)
	{
		cout << temp->data << endl;
		temp = temp->rptr;
	}
	cout << endl;
}

int main() {
	int num = 0;
	int Index = 0;
	do
	{
		cout << "Press 1 to create\nPress 2 to insert \nPress 3 to insert at Start\n"
			<< "Press 4 to to insert in the End\nPress 5 to Insert by index\nPress 6 to Delete from the start" <<
			"\nPress 7 to delete from the End\nPress 8 delete by index\n" <<
			"Press 9 to delete by Index\nPress 10 to display\n";
		cout << "Enter Choice: ";
		cin >> num;
		switch (num)
		{
		case 1:
			create();
			break;
		case 2: {
			Node* newNode = new Node();

			insert_in_Middle(newNode, newNode->data);
			break;
		}
		case 3: {
			Node* newNode = new Node();
			cout << "Enter Number: ";
			cin >> newNode->data;
			insert_At_Start(newNode, newNode->data);
			break;
		}
		case 4: {
			Node* newNode = new Node();
			cout << "Enter Number: ";
			cin >> newNode->data;
			insert_At_End(newNode, newNode->data);
			break;
		}
		case 5: {

			cout << "Enter index: ";
			cin >> num;
			insert_At_Index(num);
			break;
		}
		case 6: {
			delete_From_Start();
			break;
		}
		case 7:
		{
			delete_From_End();
			break;
		}
		case 8: {
			if (head == NULL) {
				cout << "Link list has not been created yet" << endl;
			}
			else {
				cout << "Enter index Number: ";
				cin >> Index;
				delete_By_Index(Index);

			}
		}
		case 9: {
			if (head == NULL) {
				cout << "Link list has not been created yet" << endl;
			}
			else {

				delete_By_Value();

			}
		}
		case 10:
			display();
			break;

		default:
			break;
		}
	} while (true);
}