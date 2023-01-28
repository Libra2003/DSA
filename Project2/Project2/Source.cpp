#include<iostream>
using namespace std;
#define Max 5
struct C_queue{
	int arr[Max];

	int front, rear;
};
C_queue qu;

bool isFull() {
	if (qu.front == 0 && qu.rear == 0) {
		return true;
	}
	else {
		return false;
	}
}
bool isEmpty() {
	if (qu.front == -1) {
		return true;
	}
	else {
		return false;
	}
}

void enQueue() {
	if (isFull()) {
		cout << "queue is full" < , endl;
	}
	else {
		if (isEmpty()) {

		}
	}
	
}

int main() {
	qu.front = qu.rear = -1;
}