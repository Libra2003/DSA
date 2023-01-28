#include<iostream>
using namespace std;
#define Max 11
int arr[Max] = { 5,1,7,2,45,5,3,2,8,11,9 };
void display();
int partition(int low, int high) {
	int pivot = arr[low];
	int i = low+1;
	int j = high;
	int temp;

	do
	{
		while (arr[i] <= pivot && i <Max) {
			i++;
		}
		while (arr[j] > pivot) {
			j--;
		}
		if (i<j) {
			swap(arr[i], arr[j]);
		}
	} while (i<j);
	
	swap(arr[low], arr[j]);

	return j;
}

void quick_Sort(int low, int high) {
	int partitionIndex;
	if (low < high) {
		partitionIndex = partition( low, high);
		quick_Sort( low, partitionIndex - 1);
		quick_Sort( partitionIndex + 1, high);
	}
}

void display() {
	int i = 0;
	while (i<Max)
	{
		cout << arr[i] << " ";
		i++;
	}
	cout<<endl;
}

int main() {
	cout << "Main Array" << endl;
	display();
	quick_Sort( 0, Max - 1);
	cout << "Sorted" << endl;

	display();

}