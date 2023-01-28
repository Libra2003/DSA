#include<iostream>
#include<string>
using namespace std;

struct Node {
	int data;
	Node *rptr;
	Node *lptr;

};

Node *current = NULL;
Node *first = NULL;
Node *Prev = NULL;
Node *last = NULL;

void create(int limit, int num) {	

	for (int i = 0;i < limit;i++) {
		Node *newNode = new Node();
		cout << "Enter number " << i << " : ";
		cin >> newNode->data;
		if (current == NULL) {
			current = newNode;

			first = Prev = current;
		}
		else {
			current = newNode;
			Prev->rptr = current;
			current->lptr = Prev;
			last = Prev = current;

		}
	}
}
void display() {
	if (first != NULL) {
		cout << "This LinkList is from the Start " << endl;
		current = first;
		while (current!=NULL)
		{
			cout << current->data << "-->";
			current = current->rptr;

		}
		cout << endl;
		cout << "\nThis is the Reverse LinkList " << endl;
		current = last;

		while (current!=NULL) {
			cout << current->data << "-->";
			current = current->lptr;
		}
		cout << endl;
	}
	else {
		cout << "Link list is empty" << endl;
	}
}

void search(int &num, bool &found ) {
	cout << "\nEnter the number you want to search: ";
	cin >> num;
	int i = 0;
	current = first;

	while (current!=NULL)
	{
		if (current->data == num) {
			found = true;
			cout << "Number " << current->data << " is found at " << i << endl;

			break;
		}
		else {
			found = false;
		
		}
		

		current = current->rptr;
		i++;
	}

	
}
void Delete(int &num,bool &found) {
	cout << "\nEnter the number you want to Delete: ";
	cin >> num;

	current = first;
	while (current!=NULL )
	{
		if (current->data == num) {
			if (current == first) {
				current = current->rptr;
				
				first =Prev= current ;
				current = current->rptr;
				current->lptr = NULL;
				Prev->rptr = current;
				Prev = first;
				first->lptr = NULL;
				cout << "Number has been deleted " << endl;

				found = true;
				break;

			}
			else if (current->rptr == NULL) {
				last =Prev;
				Prev->rptr = NULL;
				cout << "Number has been deleted " << endl;

				found = true;
				break;
				
			}
			else {
				current = current->rptr;
				Prev->rptr = current;
				current->lptr = Prev;
				cout << "Number has been deleted " << endl;
				found = true;
				break;
			}
			found = true;
			break;

		}
		else {
			found = false;
		}
		Prev = current;
		current = current->rptr;
	}
	if (found == false) {
		cout << "Number not found" << endl;
	}
}

void insetAtStart(int &num) {
	Node *newNode = new Node();
	cout << "Enter the number :";
	cin >> newNode->data;
	if (first == NULL) {
		first = newNode;
	}
	else {
		current = first;

		newNode->rptr = current;
		current->lptr = newNode;
		first = current = newNode;
		cout << " " << endl;
		
	}
	
}

void insertInMiddle(int &num, bool &found) {
	Node* newNode = new Node();
	cout << "Enter the number after which you want to insert: ";
	cin >> num;
	
	current = first;
	while (current!=NULL)
	{
		if (current->data == num) {
			cout << "Enter the number that you want to insert: ";
			cin >> newNode->data;
			if (current->rptr == NULL) {
				current->rptr = newNode;
				newNode->lptr = current;
				last = newNode;
				found = true;
				break;
			}
			else {
				Prev = current;
				current = current->rptr;
				Prev->rptr = newNode;
				newNode->lptr = Prev;

				current->lptr = newNode;
				newNode->rptr = current;
				found = true;
				break;
			}
			
			
		}
		else {
			found = false;
		}
		current = current->rptr;
		Prev = current;

	}
	if (found == false) {
		cout << "Number not found" << endl;
	}
}

void insertAtEnd(int &num) {
	Node *newNode = new Node();
	cout << "Enter the number you want to insert: ";
	cin >> newNode->data;
	
	if (first == NULL) {
		first =last= newNode;
	}
	else {
		current = first;
		while (current)
		{
			if (current->rptr == NULL) {
				current->rptr = newNode;
				newNode->lptr = current;
				last = newNode;
				break;
			}
			current = current->rptr;
		}
	}
	
}

void sort(bool &found) {
	current = first;
	Node *temp = current;
	int num = 0;
	while (current)
	{
		if (Prev->data>current->data)
		{
			temp = Prev;
			while (temp)
			{
				if (temp->data > current->data){
					
					num = temp->data;
					temp->data = current->data;
					current->data = num;
					temp = temp->lptr;
					current = current->lptr;
					

				}
				else {
					break;
				}
				
			}
			

		}

		Prev = current;
		current = current->rptr;
	}
}
int main() {
	int limit = 0, num = 0,choice, i = 0;
	bool found = true;
	string ask;

	do
	{
		cout << "Press 1 to Create\nPress 2 to Traverse\nPress 3 to search\nPress 4 to Delete\nPress 5 to Insert\nPress 6 to sort\nPress 7 to Quit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "How many numbers do you want to enter: ";
			cin >> limit;
			create(limit, num);
			break;
		case 2:
			do
			{
				if (first == NULL) {
					cout << "No link list has been created yet\n\nWould you like to create one?\nPress y for Yes and n for No" << endl;
					cin >> ask;
					if (ask == "y" || ask == "Y") {
						cout << "How many numbers do you want to enter: ";
						cin >> limit;
						create(limit, num);
						break;
					}
					else if (ask == "N" || ask == "n") {
						break;
					}
					else {
						cout << "Plz enter correct input" << endl;
					}

				}
				else {
					display();
					break;
				}
			} while (ask != "N" || ask != "n");
			break;
		case 3: 
			do
			{
				if (first == NULL) {
					cout << "No link list has been created yet\n\nWould you like to create one?\nPress y for Yes and n for No" << endl;
					cin >> ask;
					if (ask == "y" || ask == "Y") {
						cout << "How many numbers do you want to enter: ";
						cin >> limit;
						create(limit, num);
						break;
					}
					else if (ask == "N" || ask == "n") {
						break;
					}
					else {
						cout << "Plz enter correct input" << endl;
					}

				}
				else {
					search(num, found);
					break;


				}
			} while (ask != "N" || ask != "n");			
			
			
		break;
		case 4:
			do
			{
				if (first == NULL) {
					cout << "No link list has been created yet\n\nWould you like to create one?\nPress y for Yes and n for No" << endl;
					cin >> ask;
					if (ask == "y" || ask == "Y") {
						cout << "How many numbers do you want to enter: ";
						cin >> limit;
						create(limit, num);
						break;
					}
					else if (ask == "N" || ask == "n") {
						break;
					}
					else {
						cout << "Plz enter correct input" << endl;
					}

				}
				else {
					Delete(num, found);
					break;


				}
			} while (ask!="N"||ask!="n");
			break;
		case 5:
		
			do
			{
				if (first == NULL) {
					cout << "No link list has been created yet\n\nWould you like to create one?\nPress y for Yes and n for No" << endl;
					cin >> ask;
					if (ask == "y" || ask == "Y") {
						cout << "How many numbers do you want to enter: ";
						cin >> limit;
						create(limit, num);
						break;
					}
					else if (ask == "N" || ask == "n") {
						break;
					}
					else {
						cout << "Plz enter correct input" << endl;
					}

				}
				else {
					cout << "Press 1 to inset at Start\nPress 2 to inset in the Middle\nPress 3 to insert at the End" << endl;
					cin >> choice;
					switch (choice)
					{
					case 1:
						insetAtStart(num);
						break;
					case 2:
						insertInMiddle(num, found);
						break;
					case 3:
						insertAtEnd(num);
						break;
					default:
						break;
					}
					break;

				}
				
			} while (ask != "N" || ask != "n");
			break;
			
			break;
		case 6:
			do
			{
				if (first == NULL) {
					cout << "No link list has been created yet\n\nWould you like to create one?\nPress y for Yes and n for No" << endl;
					cin >> ask;
					if (ask == "y" || ask == "Y") {
						cout << "How many numbers do you want to enter: ";
						cin >> limit;
						create(limit, num);
						break;
					}
					else if (ask == "N" || ask == "n") {
						break;
					}
					else {
						cout << "Plz enter correct input" << endl;
					}

				}
				else {
					sort(found);
					break;


				}
			} while (ask != "N" || ask != "n");
			break;
		default:
			cout << "Plz Enter the correct input from the given options" << endl;
			break;
		}
	} while (choice!=7);
}







	