#include<iostream>
using namespace std;

int L[8] { 1,2,3,4,5 };
int MAX = 8;
int N = 5;
int i;
int pos = 0;
int DATA = 100;



void start_insert() {
	if (N < MAX) {
		for (i = N; i >= pos; i--) {
			L[i + 1] = L[i];
		}
		L[pos] = DATA;
		N = N + 1;
	}
	for (i = 0; i < N; i++) {
		cout << L[i] << endl;
	}
	
}
int input;

void Mid_Insert() {
	cout << "Enter the point on which you want to insert";
	cin >> input;
	if (N < MAX) {
		for (i = N; i >= input-1; i--) {
			L[i + 1] = L[i];

		}
		L[input-1] = DATA;
		N = N + 1;
	}
	for (i = 0; i < N ; i++) {
		cout << L[i] << endl;
	}
}
void End_Insert() {
	if (N < MAX) {
		L[N] = DATA;
		N = N + 1;
	}
	for (i = 0; i < N; i++) {
		cout << L[i] << endl;
	}
}

int main() {
	End_Insert();

}