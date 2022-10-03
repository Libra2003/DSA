#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

Node *head = NULL;
Node *first = head;
Node *last = NULL;

//This function will check wether the given index is less then or equal to the number of Nodes present
bool check(int &nodes, int index) {
	if (nodes >= index) {
		return true;
	}
	else {
		return false;
	}
}
// Function will create circular Link_List
struct Node* create(int &nodes) {
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
			if (temp->next == NULL) {
				temp->next = newNode;
				newNode->next = first;
			}
			else {
				while (temp->next != first)
				{
					temp = temp->next;
				}
				temp->next = newNode;
				last = newNode;
				last->next = first;
			}
			
		}
		nodes++;
		cout << "\nCreate Menu\nPress 1 to continue\nPress 2 to exit: "<<endl;
		cin >> choice;
		if (choice == 1) {
			create(nodes);
		}
	return head;
}

struct Node* insert_At_Index(Node*head, int index, int &nodes) {
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
				
				if (index==0)
				{
					newNode->next = head;
					first = newNode;
					head->next = first;
					last->next = first;
					break;

				}
				else if (head->next == NULL&&index==i) {
					head->next = newNode;
					newNode = last;
					newNode->next = first;

					break;

				}
				else if(index==i) {
					Prev->next = newNode;
					newNode->next = head;

					break;
				}
				Prev = head;
				head = head->next;
			}
		
			nodes++;
		}
		else {
			cout << "index is out of nodes reach" << endl;
		}
	}
	return head;
}

struct Node* insert_At_start(Node* head, int& nodes, Node*newNode) {
	if (head == NULL) {
		cout << "Link list is empty" << endl;
	}
	else {
		newNode->next = head;
		first = head;
		last->next = first;
		nodes++;
	}
	return head;
}

struct Node* insert_At_End(Node* head, int& nodes, Node* newNode) {
	if (head == NULL) {
		cout << "Link list has not been created" << endl;
	}
	else {
		head->next = newNode;
		newNode = last;
		last->next = first;
		nodes++;
	}
	return head;
}

struct Node* insert_By_Value(Node* head, int& nodes,int num) {
	if (head == NULL) {
		cout << "Link list is empty" << endl;
	}
	else {
		Node* newNode = new Node();
		Node* Prev = NULL;
		cout << "Enter number: ";
		cin >> newNode->data;
		while (head->next!=NULL)
		{
			if(newNode->data == head->data)
			if ( head->next == NULL) {
				head->next = newNode;
				newNode = last;
				last->next = first;
				nodes++;
				break;
			}
			else if (newNode->data == head->data) {
				Prev->next = newNode;
				newNode->next = head;
				nodes++;
				break;
			}
			Prev = head;
			head = head->next;
		}
	}

	return head;
}

struct Node* Delete(Node*head, int &nodes, Node*newNode) {
	Node* Prev = NULL;
	if (head == NULL) {
		cout << "Link list has not been created yet" << endl;
	}
	else {
		while (head->next!=first)
		{
			if (newNode->data == head->data) {
				if (head->next == first) {
					Prev->next = NULL;
					Prev = last;
					last->next = first;
				}
				else if (Prev == NULL && head->next == NULL) {
					head = NULL;
				}
				else if (Prev == NULL) {
					Prev = head;
					head = head->next;
					Prev = NULL;
					last->next = head;
					first = head;
				}
				else {
					Prev->next = head->next;
				}
				break;
			}
			Prev = head;
			head = head->next;
		}
	}
	return head;
}

struct Node* delete_By_Index(Node*head,int &nodes,int index) {
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
					else if (index == i && head->next == NULL) {
						Prev->next == NULL;
						break;
					}
					else {
						Prev->next = head->next;
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
			head = head->next;
		}

			
	}
	
	return head;
}

void display() {
	Node* temp = head;
	while (temp->next!=first)
	{
		cout << temp->data << endl;
		temp = temp->next;
	}
	cout <<temp->data<< endl;
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
	} while (num==1);

}