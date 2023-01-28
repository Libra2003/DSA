#include<iostream>
using namespace std;


struct Node {
	int data;
	Node*lptr, *rptr, *pptr;
	
};

Node *root = NULL;
Node *child = NULL;

bool isEmpty() {
	if (root == NULL) {
		return true;
	}
	else {
		return false;
	}
}

void create() {
	int num;
	do
	{
		Node *newNode = new Node();
		cout << "Enter number: ";
		cin >> newNode->data;
		num = newNode->data;
		if (isEmpty()) {
			child = root = newNode;
		}
		else {
			Node*temp = child;
			do
			{
				
				while (temp->lptr != NULL && temp->data > num)
				{
					temp = temp->lptr;
				}

				while (temp->rptr != NULL && temp->data <= num)
				{
					temp = temp->rptr;
				}

			} while (temp->rptr != NULL && temp->data<num || temp->lptr != NULL && temp->data>num);

			if (temp->lptr == NULL && temp->data > num) {
				temp->lptr = newNode;
				newNode->pptr = temp;
			}
			else if (temp->rptr == NULL && temp->data < num) {
				temp->rptr = newNode;
				newNode->pptr = temp;
			}
		}
		cout << "Press 1 to enter more" << endl;
		cout << "Press 2 exit to the main menu" << endl;
		cin >> num;

	} while (num==1);

}

void inOrder_Display(Node*root) {
	if (root == NULL) {
		return;
	}

	inOrder_Display(root->lptr);
	cout << root->data << " ";
	inOrder_Display(root->rptr);

}

void search() {
	Node *temp = child;
	Node *temp2 = temp;
	int found = 0;
	int num = 0;
	cout << "Enter the number you want to search: ";
	cin >> num;
	if (child == NULL) {
		cout << "Tree is empty" << endl;
	}
	else if (temp->lptr == NULL && temp->rptr == NULL &&temp->data==num) {
		cout << "The number " << temp->data << " is found at the root node" << endl;
	}
	else {
		do
		{
			while (temp != NULL && temp->data >= num &&found!=2 )
			{
				if (temp->data == num) {
					found = 1;
					temp2 = temp;
					temp = temp->lptr;
					break;
				}
				temp = temp->lptr;

			}

			while (temp!= NULL && temp->data <= num &&found!=1)
			{
				if (temp->data == num) {
					found = 2;
					temp2 = temp;
					temp = temp->rptr;
					break;
				}
				temp = temp->rptr;

			}

		} while (temp != NULL && found != 0);
		
		if (found == 1) {
			temp = temp2->pptr;
			cout << "Number " << temp2->data << " is found in the left sub tree " << endl;
			cout << "Parent of Number " << temp2->data << " is " << temp->data << endl;

		}
		else if (found == 2) {
			temp = temp2->pptr;
			cout << "Number " << temp->data << " is found in the right sub tree " << endl;
			cout << "Parent of Number " << temp->data << " is " << temp2->data << endl;
		}
		else {
			cout << "Number not found" << endl;
		}
	}

}

int maximum();
int minimum();

void Delete() {
	Node*newNode = new Node();
	Node*temp = child;
	Node*Prev = temp;
	cout << "Enter the number you want to delete: ";
	cin >> newNode->data;
	if (child != NULL) {
		if (child->lptr == NULL && child->rptr == NULL && newNode->data == child->data) {
			cout << "Number found on the top node" << endl;
			cout << "Number deleted" << endl;
			child = NULL;
		}
		else {
			bool found = false;
			do
			{
				while (temp != NULL && temp->data > newNode->data)
				{
					temp = temp->lptr;
				}
				while (temp != NULL && temp->data < newNode->data)
				{
					temp = temp->rptr;
				}
				if (temp!=NULL && temp->data == newNode->data) {

					found = true;
					break;
				}

			} while (temp != NULL && temp->data != newNode->data);

			if (found == true) {
				do
				{
					Prev = temp;

					if (temp->lptr != NULL) {
						temp->data = temp->lptr->data;
						temp = temp->lptr;
					}
					else if (temp->rptr != NULL) {
						temp->data = temp->rptr->data;
						temp = temp->rptr;
					}


				} while (temp->lptr != NULL || temp->rptr != NULL);

				if (Prev->lptr==temp){
					Prev->lptr = NULL;
				}
				else if (Prev->rptr == temp) {
					Prev->rptr = NULL;
				}
				else {
					temp->lptr = NULL;
					temp->rptr = NULL;
				}
			}
			else {
				cout << "Number not found in the tree" << endl;
			}


		}
	}
	else {
		cout << "Node doesn't exist" << endl;
	}
}

int minimum(){ 
	Node *temp = child;

	while (temp->lptr != NULL) {
		temp = temp->lptr;
	}
	return temp->data;
}

int maximum() {
	Node *temp = child;
	while (temp->rptr != NULL) {
		temp = temp->rptr;
	}
	return temp->data ;
}



int main() {
	int choice = 0;
	do
	{
		cout << "Press 1 to create/insert" << endl;
		cout << "Press 2 to display left tree" << endl;
		cout << "Press 3 to to search the tree" << endl;
		cout << "Press 4 to to find the minimum in the tree" << endl;
		cout << "Press 5 to to find the maximum in the tree" << endl;
		cout << "Press 6 to to delete" << endl;
		cout << "Press 8 to quit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			create();
			break;
		case 2:
			inOrder_Display(child);
			cout << endl;
			break;
		case 3:
			search();
			break;
		case 4:
			cout << "Minimum Number is: " << minimum() << endl;
			break;
		case 5:
			cout << "Maximum Number is: " << maximum() << endl;
			break;
		case 6:
			Delete();
			break;
		case 8:
			exit(1);
		default:
			cout << "Wrong input try again\n" << endl;
			break;
		}

	} while (choice!=8);
}
