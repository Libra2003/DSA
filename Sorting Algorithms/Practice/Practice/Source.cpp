#include <iostream>
using namespace std;
const int SIZE = 6;

void BubbleSort(int A[])
{
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE - i-1; j++) {
			if (A[j] > A[j + 1]) {
				swap(A[j], A[j + 1]);
			}
		}
	}
}
void display(int A[]) {
	for (int i = 0; i < SIZE; i++) {
		cout << A[i] << " ";
	}
}
int main() {
	int A[SIZE];
	for (int i = 0; i < SIZE; i++) {
		cin >> A[i];
	}

	BubbleSort(A);
	display(A);
	system("pause");
	return 0;
}