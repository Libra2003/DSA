#include<iostream>
using namespace std;
#define Max 4
struct Node {
	 char arr[Max] = { 'a','b','c','d' };
	 char arr1[Max];

	int front;
	int	rear;
};
Node qu;

void enqeue(int i) {

	qu.arr[qu.rear] = qu.arr1[i];
	qu.rear++;
	qu.front--;
}

char deqeue() {
	char value;
	value = qu.arr[qu.front] ;
	qu.arr[qu.front] = '0';
	qu.front++;
	qu.rear--;
	return value;
}
void display() {
	for (int i = 0; i < Max; i++)
	{
		cout <<qu.arr[i] << " ";

	}
	cout << endl;
}
int main() {
	qu.rear = Max;
	qu.front = 0;
	display();
	for (int i = 0; i <Max; i++) {
		qu.arr1[i]= deqeue();
	}
	for (int i = Max-1 ; i >= 0; i--) {
		enqeue(i);
	}
	display();

}