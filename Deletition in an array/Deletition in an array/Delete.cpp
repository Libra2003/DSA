#include<iostream>
using namespace std;

int L[10] = {2, 32, 13, 45,26,9,11};
int K;
int Max = 10;
int n = 7;
int i;

void Delete() {
	cout << "Enter the element to be deleted : ";
	cin >> K;
	for (i = 0; i < Max; i++) {
		if (L[i] == K) {
			for (int j = i; j < Max-1; j++) {
				L[j] = L[j + 1];
			}
			Max--;
		}
	}
	for (i = 0; i < Max; i++) {                                                                                 
		cout << L[i] << endl;
	}
}

int main() {
	Delete();

}