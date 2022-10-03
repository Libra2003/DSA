#include<iostream>
using namespace std;

int indDeletion(int arr[], int &Size, int element, int capacity, int index, int num, bool &found) {


	if (num == 1) {
			if (index >= Size) {
				return -1;
			}
			else {
				for (int i = index;i < Size;i++) {
					num = arr[i];
					arr[i] = arr[i + 1];
				}
				return 1;

			}
		
		
		Size--;
	}
	else if (num == 2) {
		cout << "Enter number: ";
		cin >> num;
		for (int i = 0;i < Size;i++) {
			if (num == arr[i]) {
				for (int j = i;j < Size;j++) {
					arr[j] = arr[j + 1];
				}
				Size--;
				found = true;
				return 1;
			}
			else {
				false;
			}
		
		}
		if (found == false) {
			cout << "Number not found" << endl;
		}
	}

}
void show(int arr[], int Size) {
	for (int i = 0;i < Size ;i++) {
		cout << arr[i] << "\n";
	}
}

int main() {
	int arr[10] = { 11,23,32,43,54,68 };
	int Size = 6, element = 45, index = 3;
	int num = 0;
	bool found = true;
	cout << "Press 1 to delete by index\nPress 2 to delete by number\n";
	cin >> num;
	indDeletion(arr, Size, element, 10, index, num, found);
	show(arr, Size);


}