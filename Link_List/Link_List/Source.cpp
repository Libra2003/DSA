#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};
Node* current = NULL;

void create() {
	Node* newNode = new Node();
	int num = 0;
	cout << "Enter Number: ";
	cin >> newNode->data; 

	if (current == NULL) {
		current = newNode;

	}
	else {
		Node* temp = current;
		while (temp->next!=NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
	}

	cout << "\nPress 1 to enter more\nPress 2 to for main menu " << endl;
	cin >> num;
	if (num == 1) {
		create();
	}

	
}

Node* insert_At_Start(struct Node*newNode,int data) {

	if (current == NULL) {
		current = newNode;
	}
	else {
		newNode->next = current;
		current = newNode;
	}
	return current;
}

Node* insert_in_Middle(struct Node* newNode, int data) {
	int num = 0;
	
	Node* temp = current;
	Node* Prev = temp;
	if (temp == NULL) {
		cout << "Link list hasn't been created yet " << endl;
		return temp;
	}
	cout << "Enter the number afther which you want to insert: ";
	cin >> num;
	while (temp!=NULL)
	{
	
		if (num == Prev->data) {
			cout << "Enter Number: ";
			cin >> newNode->data;
			if (Prev == temp) {
			temp = temp->next;
			}
		
			if (Prev->next == NULL) {
				Prev->next = newNode;
			}
			else {
				Prev->next = newNode;
				newNode->next = temp;
			}		
			break;
		}
		else if (temp->next == NULL&&num==temp->data) {
			cout << "Enter Number: ";
			cin >> newNode->data;
			temp->next = newNode;
			temp = temp->next;
			break;
		}
	
		
		Prev = temp;
		temp = temp->next;

	}
	if (Prev == NULL) {

		cout << "Number not found " << endl;

	}
	return temp;

}

Node* insert_At_End(struct Node* newNode, int data) {
	Node* temp = current;
	while (temp->next!=NULL)
	{
		temp = temp->next;
	}
	temp->next = newNode;
	return temp;
}

Node* insert_At_Index(int index) {
	Node* newNode = new Node();
	Node* temp = current;
	Node* Prev = NULL;
	if (index == 0&&temp->next) {
		newNode->next = temp;
		
	}
	else {
		for (int i = 0; i <= index; i++)
		{
			if (index == i) {
				cout << "Enter Number : ";
				cin >> newNode->data;
				if (Prev == NULL) {
					newNode->next = temp;
					break;
				}
				else if (temp == NULL) {
					Prev->next = newNode;
					break;
				}
				else {
					Prev->next = newNode;
					newNode->next = temp;
					break;
				}
				if (temp == NULL) {
					break;
				}

			}
			Prev = temp;
			temp = temp->next;

		}
	}
	
	return current;
}

Node* delete_From_Start() {
	Node* temp = current;
	Node* Prev = current;
	if (current == NULL) {
		cout << "Link list is NULL" << endl;
	}
	else {
		
		if (temp->next == NULL) {
			temp = NULL;
			return temp;
		}
		else {
			Prev = temp;
			temp = temp->next;
			Prev = NULL;
			current = temp;
			return current;
		}
		
	}

}

Node* delete_From_End() {
	if (current == NULL) {
		cout << "Link list doesn't exit" << endl;
		return NULL;
	}
	else {
		Node* temp = current;
		if (temp->next != NULL) {
			Node* Prev = temp;
			while (temp->next != NULL)
			{
				Prev = temp;
				temp = temp->next;
			}
			Prev->next = NULL;

		}
		else {
			temp = NULL;
		}
		return current;

	}
}

Node* delete_By_Value() {

	if (current == NULL) {
		cout << "Link list is empty" << endl;
	}
	else {
		Node* newNode = new Node();
		cout << "Enter Number: ";
		cin >> newNode->data;

		Node* temp = current;
		Node* Prev = NULL; 
		while (temp!=NULL)
		{
			if (temp->data == newNode->data) {
				if (Prev == NULL) {
					temp = NULL;
					break;
				}
				else {
					temp = temp->next;
					Prev->next = temp;
					break;
				}
			
			}
			Prev = temp;
			temp = temp->next;

		}
	}
	return current;
}

Node* delete_By_Index(int Index) {
	Node* temp = current;
	Node* Prev = NULL;
	Node* newNode = new Node();
	for (int i =  0;i <= Index;i++) {
		if (Index==i) {
			if (temp->next == NULL) {
				temp->next = newNode;
			}
			else if (Prev != NULL) {
				temp = temp->next;
				Prev->next = temp;
				current = Prev;
				return current;
			}
			
		}
		else if (Index==0) {
			newNode->next = temp;
			return current;
		}
		Prev = temp;
		temp = temp->next;
	}

}

Node* sort() {
	Node* temp = current;

	while (temp != NULL) {
		Node* temp1 = temp->next;
		while (temp1 != NULL)
		{
			if (temp->data > temp1->data) {
				swap(temp->data, temp1->data);
			}
			temp1 = temp1->next;
		}
		temp = temp->next;

	}
	return current;
}

void display() {
	cout << endl;
	Node* temp = current;
	while (temp!=NULL)
	{
		cout << temp->data << endl;
		temp = temp->next;
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
			"Press 9 to delete by Index\nPress 10 to display\nPress 11 to sort\n\n";
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
			if (current == NULL) {
				cout << "Link list has not been created yet" << endl;
			}
			else {
				cout << "Enter index Number: ";
				cin >> Index;
				delete_By_Index(Index);

			}
			break;
		}
		case 9: {
			if (current == NULL) {
				cout << "Link list has not been created yet" << endl;
			}
			else {
				delete_By_Value();
			}
			break;
		}
		case 10:
			display();
			break;

		case 11:
			sort();
			break;
		default:
			cout << "plz enter correct input" << endl;
			break;
		}
	} while (true);
}