#include<iostream>
using namespace std;


struct Node {
	int data;
	Node* left, * right, * parent;

};

Node* root = NULL;

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
		Node* newNode = new Node();
		cout << "Enter number: ";
		cin >> newNode->data;
		num = newNode->data;
		if (isEmpty()) {
			root = root = newNode;
		}
		else {
			Node* temp = root;
			do
			{

				while (temp->left != NULL && temp->data > num)
				{
					temp = temp->left;
				}

				while (temp->right != NULL && temp->data <= num)
				{
					temp = temp->right;
				}

			} while (temp->right != NULL && temp->data<num || temp->left != NULL && temp->data>num);

			if (temp->left == NULL && temp->data > num) {
				temp->left = newNode;
				newNode->parent = temp;
			}
			else if (temp->right == NULL && temp->data < num) {
				temp->right = newNode;
				newNode->parent = temp;
			}
		}
		cout << "Press 1 to enter more" << endl;
		cout << "Press 2 exit to the main menu" << endl;
		cin >> num;

	} while (num == 1);

}

void inOrder_Treversal(Node* root) {
	if (root == NULL) {
		return;
	}

	inOrder_Treversal(root->left);
	cout << root->data << " ";
	inOrder_Treversal(root->right);

}

void preOrder_Treversal(Node* root) {
	if (root != NULL) {
		cout<<root->data<<" ";
		preOrder_Treversal(root->left);
		preOrder_Treversal(root->right);
	}
}

void postOrder_Treversal(Node* root) {
	if (root != NULL) {
		postOrder_Treversal(root->left);
		postOrder_Treversal(root->right);
		cout << root->data << " ";
	}
}

void search() {
	Node* temp = root;
	Node* temp2 = temp;
	int found = 0;
	int num = 0;
	cout << "Enter the number you want to search: ";
	cin >> num;
	if (root == NULL) {
		cout << "Tree is empty" << endl;
	}
	else if (temp->data == num) {
		cout << "The number " << temp->data << " is found at the root node" << endl;
	}
	else {
		do
		{
			while (temp != NULL && temp->data >= num && found != 2)
			{
				if (temp->data == num) {
					found = 1;
					temp2 = temp;
					temp = temp->left;
					break;
				}
				temp = temp->left;

			}

			while (temp != NULL && temp->data <= num && found != 1)
			{
				if (temp->data == num) {
					found = 2;
					temp2 = temp;
					temp = temp->right;
					break;
				}
				temp = temp->right;

			}

		} while (temp != NULL && found != 0);

		if (found == 1) {
			temp = temp2->parent;
			cout << "Number " << temp2->data << " is found in the left sub tree " << endl;
			cout << "Parent of Number " << temp2->data << " is " << temp->data << endl;

		}
		else if (found == 2) {
			temp = temp2->parent;
			cout << "Number " << temp->data << " is found in the right sub tree " << endl;
			cout << "Parent of Number " << temp->data << " is " << temp2->data << endl;
		}
		else {
			cout << "Number not found" << endl;
		}
	}

}

Node* maximum(Node*root);
Node* minimum(Node*root);

Node* successor(Node* root) {
	if (root->right != NULL) {
		return minimum(root->right);

	}
	else {
		
		Node* y = root->parent;
		while (y!=NULL&&root==y->right)
		{
			root = y;
			y = y->parent;
		}
		if (y == NULL) {
			return maximum(root);
			y = root->parent;
			y->right = NULL;

		}
		else {
			return y;
		}
	}
	
}

Node* predessessors(Node* root) {
	if (root->left != NULL) {
		return maximum(root->left);
	}
	else {
		Node* y = root->parent;
		while (y!=NULL && root==y->left)
		{
			root = y;
			y = y->parent;
		}
		if (y == NULL) {
			return minimum(root);
		}
		else {
			return y;
		}
	}
}

void Delete(Node* newNode, Node*root) {
	Node* temp = root;
	Node* Prev = temp;
	bool found = false;

	Node* newData;
	if (root==NULL)
	{
		cout << "Tree is Empty" << endl;
	}
	else {
		
		do
		{
			while (temp->data>newNode->data)
			{
				Prev = temp;
				temp = temp->left;

			}
			while (temp->data < newNode->data)
			{
				Prev = temp;
				temp = temp->right;
	
			}
			if (temp->data == newNode->data) {
				if (temp->left != NULL) {
					Node* newRoot = temp;
					if (newRoot->right != NULL) {
						newData = minimum(root->right);
						newData = newData->parent;
						newData->left = NULL;
						temp->data = newData->data;
					}
					else {

						Node* y = root->parent;
						while (y != NULL && root == y->right)
						{
							root = y;
							y = y->parent;
						}
						if (y == NULL) {
							newData = maximum(root);
							y = root->parent;
							y->right = NULL;

						}
						else {
							y->left = NULL;
						}
					}
				}
				














				//This IF statement check if the number to be deleted is the last one or not
				if (temp->left == NULL && temp->right == NULL) {
					/*This If statements check if the Previous pointer is smaller then the ones to be deleted
					if that is true then the Data to be deleted is deleted by making that pointer null
					It checks wether the last number is on right side of the number or not*/
					if (temp->data > Prev->data) {
						Prev->right = NULL;
					}
					//This else if statement checks if the last number is left side of the uper number or not
					else if (temp->data < Prev->data) {
						Prev->left = NULL;
					}

				}
				
				break;
			}

		} while (temp!=NULL);

		if (found == true) {

		 }

	}


}

Node* minimum(Node*root) {
	Node* temp = root;

	while (temp->left != NULL) {
		temp = temp->left;
	}
	return temp;
}

Node* maximum(Node*root) {
	Node* temp = root;
	while (temp->right != NULL) {
		temp = temp->right;
	}
	return temp;
}



int main() {
	int choice = 0;
	do
	{
		cout << "Press 1 to create/insert" << endl;
		cout << "Press 2 to inOrder_Treversal" << endl;
		cout << "Press 3 to preOrder_Treversal" << endl;
		cout << "Press 4 to postOrder_Treversal" << endl;
		cout << "Press 5 to to search the tree" << endl;
		cout << "Press 6 to to find the minimum in the tree" << endl;
		cout << "Press 7 to to find the maximum in the tree" << endl;
		cout << "Press 8 to to delete" << endl;
		cout << "Press 9 to quit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			create();
			break;
		case 2:
			inOrder_Treversal(root);
			cout << endl;
			break;
		case 3:
			preOrder_Treversal(root);
			cout << endl;
			break;
		case 4:
			postOrder_Treversal(root);
			cout << endl;
			break;
		case 5:
			search();
			break;
		case 6:
			cout << "Minimum Number is: " << minimum(root) << endl;
			break;
		case 7:
			cout << "Maximum Number is: " << maximum(root) << endl;
			break;
		case 8: {
			  Node* newNode = new Node();
			  cout << "Enter the number you want to delete: ";
			  cin >> newNode->data;
			  Delete(newNode, root);
			  break;
		}
		case 9:
			exit(1);
			break;
		default:
			cout << "Wrong input try again\n" << endl;
			break;
		}

	} while (choice != 9);
}
