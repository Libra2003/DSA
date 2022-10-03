#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* r;
	Node* l;
};

Node* head = NULL;
Node* first = head;
Node* last = NULL;

//This function will check wether the given index is less then or equal to the number of Nodes present
bool check(int& nodes, int index) {
	if (nodes >= index) {
		return true;
	}
	else {
		return false;
	}
}
// Function will create circular Link_List
struct Node* create(int& nodes) {
	Node* newNode = new Node();
	int choice = 0;


	cout << "Enter Number: ";
	cin >> newNode->data;
	if (head == NULL) {
		head = newNode;
		first = head;
	}
	else {
		Node* temp = head;
		if (temp->r == NULL) {
			temp->r = newNode;
			newNode->r = first;
			newNode->l = temp;
		}
		else {
			while (temp->r != first)
			{
				temp = temp->r;
			}
			temp->r = newNode;
			newNode->l = temp;
			last = newNode;
			last->r = first;
		}

	}
	nodes++;
	cout << "\nCreate Menu\nPress 1 to continue\nPress 2 to exit: " << endl;
	cin >> choice;
	if (choice == 1) {
		create(nodes);
	}
	return head;
}

struct Node* insert_At_Index(Node* head, int index, int& nodes) {
	Node* newNode = new Node();
	Node* Prev = NULL;
	if (head == NULL) {
		cout << "Link list has not been created yet" << endl;
	}
	else {

		if (check(nodes, index)) {
			cout << "Enter the number that you want to insert: ";
			cin >> newNode->data;
			for (int i = 0; i <= index; i++)
			{

				if (index == 0)
				{
					newNode->r = head;
					head->l = newNode;
					first = newNode;
					head->r = first;
					last->r = first;
					break;

				}
				else if (head->r == NULL && index == i) {
					head->r = newNode;
					newNode->l = head;
					newNode = last;
					newNode->r = first;

					break;

				}
				else if (index == i) {
					Prev->r = newNode;
					newNode->l = Prev;
					newNode->r = head;
					head->l = newNode;

					break;
				}
				Prev = head;
				head = head->r;
			}

			nodes++;
		}
		else {
			cout << "index is out of nodes reach" << endl;
		}
	}
	return head;
}

struct Node* insert_At_start(Node* head, int& nodes, Node* newNode) {
	if (head == NULL) {
		cout << "Link list is empty" << endl;
	}
	else {
		newNode->r = head;
		head->l = newNode;
		first = head;
		last->r = first;
		nodes++;
	}
	return head;
}

struct Node* insert_At_End(Node* head, int& nodes, Node* newNode) {
	if (head == NULL) {
		cout << "Link list has not been created" << endl;
	}
	else {
		head->r = newNode;
		newNode->l = head;
		newNode = last;
		last->r = first;
		nodes++;
	}
	return head;
}

struct Node* insert_By_Value(Node* head, int& nodes, int num) {
	if (head == NULL) {
		cout << "Link list is empty" << endl;
	}
	else {
		Node* newNode = new Node();
		Node* Prev = NULL;
		cout << "Enter number: ";
		cin >> newNode->data;
		while (head->r != NULL)
		{
			if (newNode->data == head->data)
				if (head->r == NULL) {
					head->r = newNode;
					newNode->l = head;
					newNode = last;
					last->r = first;
					nodes++;
					break;
				}
				else if (newNode->data == head->data) {
					Prev->r = newNode;
					newNode->l = Prev;
					newNode->r = head;
					head->l = newNode;
					nodes++;
					break;
				}
			Prev = head;
			head = head->r;
		}
	}

	return head;
}

struct Node* Delete(Node* head, int& nodes, Node* newNode) {
	Node* Prev = NULL;
	if (head == NULL) {
		cout << "Link list has not been created yet" << endl;
	}
	else if (newNode->data == first->data) {
		first = first->r;
		first->l = NULL;
	}
	else {
		while (head != first)
		{
			if (newNode->data == head->data) {
				if (head->r == first) {
					Prev->r = NULL;
					Prev = last;
					last->r = first;
					first->l = Prev;
					
				}
				else if (Prev == NULL && head->r == NULL) {
					head = NULL;
				}
				else if (Prev == NULL) {
					Prev = head;
					head = head->r;
					Prev = NULL;
					last->r = head;
					first = head;
				}
				else {
					Prev->r = head->r;
				}
				break;
			}
			Prev = head;
			head = head->r;
		}
	}
	return head;
}

struct Node* delete_By_Index(Node* head, int& nodes, int index) {
	if (head == NULL) {
		cout << "Link list is empty" << endl;
	}
	else {
		Node* Prev = NULL;
		cout << "Enter Index Number: ";
		cin >> index;
		for (int i = 0; i <= nodes; i++)
		{
			if (index == i) {
				if (check(nodes, index)) {

					if (index == 0) {
						head = NULL;
						break;
					}
					else if (index == i && head->r == NULL) {
						Prev->r == NULL;
						break;
					}
					else {
						Prev->r = head->r;
						head->l = Prev->l;
						break;
					}
				}
			}
			else {
				cout << "Index exceeds the Preent number of nodes" << endl;
				break;
			}
			if (head == NULL) {
				break;
			}

			Prev = head;
			head = head->r;
		}


	}

	return head;
}

void display() {
	Node* temp = head;
	do
	{
		cout << temp->data << endl;
		temp = temp->r;
	} while (temp != first);
	cout << temp->data << endl;

	Node* temp2 = temp;
	while (temp2)
	{
		cout << temp2->data << endl;
		temp2 = temp2->l;
	}

}

int main() {

	int index = 0, nodes = 0;
	int num = 0;
	do
	{
		cout << "Press 1 to create\nPress 2 to insert at index \nPress 3 to insert at Start\n"
			<< "Press 4 to to insert in the End\nPress 5 to Delete " <<
			"\nPress 6 to delete by Index\nPress 7 to display\n";
		cout << "Enter Choice: ";
		cin >> num;
		switch (num)
		{
		case 1:
			create(nodes);
			break;
		case 2: {
			cout << "Enter index: ";
			cin >> index;
			insert_At_Index(head, index, nodes);
			break;
		}
		case 3: {
			Node* newNode = new Node();
			cout << "Enter number: ";
			cin >> newNode->data;
			insert_At_start(head, nodes, newNode);
			break;
		}
		case 4: {
			Node* newNode = new Node();
			cout << "Enter number: ";
			cin >> newNode->data;
			insert_At_End(head, nodes, newNode);
			break;
		}
		case 5: {
			Node* newNode = new Node();
			cout << "Enter Number: ";
			cin >> newNode->data;
			Delete(head, nodes, newNode);
			break;
		}
		case 6: {
			delete_By_Index(head, nodes, index);
			break;
		}
		case 7:
			display();
			break;

		default:
			cout << "Plz enter the correct input " << endl;
			break;
		}
		cout << "\nMain menu\nPress 1 to continue\nPress 2 to quit" << endl;
		cin >> num;
	} while (num == 1);

}