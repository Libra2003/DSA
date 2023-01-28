#include<iostream>
using namespace std;

void store_Data(int arr_1[], int Max_1, int input_1, int &n) {
	int num;
	if (input_1 < Max_1 && input_1>0) {
		for (int i = 0; i < input_1; i++) {
			cout << "Enter No." << i << ": ";
			cin >> num;
			arr_1[i] = num;
			n++;

		}
	}
	else {
		cout << "The limit of the array is 10 pls enter number less then 10 and greater than 0" << endl;
	}

}
void display_Data(int arr_1[], int &input_1, int &n) {
	for (int i = 0; i < n; i++) {
		cout << "Number: " << arr_1[i] << " is at: " << i << endl;
	}

}
void search(int arr_1[], int &n, int &input_1, bool &found_1, int &num_1) {
	for (int i = 0; i < n; i++) {
		if (arr_1[i] == input_1)
		{

			num_1 = arr_1[i];
			found_1 = true;
			break;
		}
		else {
			found_1 = false;
		}
	}
	if (found_1 == true) {
		cout << "Number found: " << num_1 << " at: " << num_1 << endl;

	}
	else if (found_1 == false) {
		cout << "Number not found " << endl;
	}
}
void insert_At_Start(int arr_1[], int &pos_1, int &n, int &num_1) {
	pos_1 = 0;
	if (n > 1) {
		for (int i = n; i >= pos_1; i--) {
			arr_1[i + 1] = arr_1[i];
		}

		arr_1[pos_1] = num_1;
		n++;
	}


}
void insert_At_Middle(int arr_1[], int& pos_1, int& n, int& num_1) {

	if (pos_1 < n && pos_1>0) {
		for (int i = n; i >= pos_1; i--) {
			arr_1[i + 1] = arr_1[i];
		}
		arr_1[pos_1] = num_1;
		n++;
	}
}
void insert_At_End(int arr_1[], int& pos_1, int& n, int& num_1) {
	pos_1 = n;
	if (pos_1 == n) {
		arr_1[pos_1] = num_1;
		n++;
	}
}
void del_pos(int arr_1[], int &pos_1, int &n) {
	if (pos_1 > 0 && pos_1 < n) {
		for (int i = pos_1; i < n; i++) {
			arr_1[i] = arr_1[i + 1];
		}
		n--;
	}
}
void del_Data(int arr_1[], int& n, int& num_1) {
	for (int i = 0; i < n; i++) {
		if (arr_1[i] == num_1) {
			for (int j = i; j < n; j++) {
				arr_1[j] = arr_1[j + 1];

			}
			n--;
		}
	}
}
void sort(int arr_1[], int &n) {
	int temp;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr_1[i] > arr_1[j]) {
				temp = arr_1[i];
				arr_1[i] = arr_1[j];
				arr_1[j] = temp;
			}
		}
	}
}
int Traverse_Max(int arr_1[], int &n, int& MaxNo, int& pos_1) {
	MaxNo = arr_1[0];
	for (int i = 0; i < n; i++) {
		if (arr_1[i] > MaxNo) {
			MaxNo = arr_1[i];
			pos_1 = i;
		}
	}

	return MaxNo, pos_1;

}
int Traverse_Min(int arr_1[], int& n, int& Min_1, int& pos_1) {
	Min_1 = arr_1[0];
	for (int i = 0; i < n; i++) {
		if (arr_1[i] < Min_1) {
			Min_1 = arr_1[i];
			pos_1 = i;
		}
	}

	return Min_1, pos_1;

}

int main() {
	int arr[10], Max = 10, input, i, pos, N = 0, choice = 0, num, MaxN, Min = 0;
	bool found, loop;
	do
	{
		cout << "\n-->MAIN MENU" << endl;
		cout << "-->Press 1 for Storing Data\n-->Press 2 for Displaying Data \n-->Press 3 for Inserting an element" <<
			"\n-->Press 4 for searching an element"
			<< "\n-->Press 5 Deleting an element from an array" <<
			"\n-->Press 6 for sorting an array\nPress 7 Treversing Maximum and minimum number in an array\n-->Press 8 to Quit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: {
			cout << "Enter Size of the array: ";
			cin >> input;
			store_Data(arr, Max, input, N);
			break;
		}
		case 2: {
			display_Data(arr, input, N);

			break;
		}
		case 3: {
			bool found_A = true;
			do
			{
				cout << "\nPress 1 for Inserting at the start\nPress 2 for Inserting in the middle\nPress 3 for Inserting at the End" <<
					"\nPress 4 To Quit" << endl;
				cin >> choice;
				switch (choice)
				{
				case 1: {

					cout << "Enter Number you want to insert: ";
					cin >> num;
					insert_At_Start(arr, pos, N, num);
					break;

				}
				case 2: {
					cout << "Enter the point on which you want to insert the number : ";
					cin >> pos;
					cout << "Enter Number you want to insert: ";
					cin >> num;
					insert_At_Middle(arr, pos, N, num);
					break;
				}
				case 3: {
					cout << "Enter Number you want to insert: ";
					cin >> num;
					insert_At_End(arr, pos, N, num);
					break;
				}
				case 4: {
					found_A = false;
					break;
				}
				default:
					break;
				}


			} while (found_A == true);
			break;
		}
		case 4: {
			cout << "Enter Number you want to search: ";
			cin >> input;
			search(arr, N, input, found, num);
			break;

		}
		case 5: {
			bool del_repeat = true;
			while (del_repeat == true)
			{
				cout << "\nPress 1 To Delete by position\nPress 2 To Delete by Number\nPress 3 To quit" << endl;
				cin >> choice;
				switch (choice)
				{
				case 1:
				{
					cout << "Enter the postion of the number you want to delte: ";
					cin >> pos;
					del_pos(arr, pos, N);
					break;
				}
				case 2:
				{
					cout << "Enter the number which you want to delete: ";
					cin >> num;
					del_Data(arr, N, num);;
					break;
				}
				case 3: {
					del_repeat = false;
					break;
				}

				default:
					cout << "Plz enter the correct input" << endl;

				}

			}
			break;
		}
		case 6: {
			sort(arr, N);
			break;
		}
		case 7: {
			bool tre_Repeat = true;
			while (tre_Repeat == true)
			{
				cout << "\nPress 1 To find Maximum Number\nPress 2 to find the minimum Number\nPress 3 to Quit" << endl;
				cin >> choice;
				switch (choice)
				{
				case 1:
				{
					Traverse_Max(arr, N, MaxN, pos);
					cout << "Maximum number " << MaxN << " is at " << pos << endl;
					break;
				}
				case 2:
				{
					Traverse_Min(arr, N, Min, pos);
					cout << "Minimum number " << Min << " is at " << pos << endl;
					break;
				}
				case 3:
				{
					tre_Repeat = false;
					break;
				}

				default:
					cout << "Plz enter the correct input" << endl;
					break;
				}
			}



		}
		case 8: {
			loop = false;
			break;
		}
		default:
			break;
		}

	} while (choice !=8);



	return 0;




}