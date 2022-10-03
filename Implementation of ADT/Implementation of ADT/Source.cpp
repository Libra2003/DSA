#include<iostream>
using namespace std;

struct my_Array {
	int total_Size;
	int used_Size;
	int* ptr;

};

void create(struct my_Array* a, int tSize, int uSize) {
	a->total_Size = tSize;
	a->used_Size = uSize;
	a->ptr = (int*)malloc(tSize * (sizeof(int)));
}
void setVal(struct my_Array* a) {
	int n = 0;
	for (int i = 0; i < a->used_Size; i++)
	{
		cout<<"Enter element %d: ";
		scanf_s("%d", &n);
		(a->ptr)[i] = n;

	}
}
void show(struct my_Array* a) {
	for (int i = 0; i < a->used_Size;i++) {
		cin>> a->ptr[i];
	}
}



int main() {
	struct my_Array marks;
	create(&marks, 10, 5);
	setVal(&marks);
	show(&marks);
}