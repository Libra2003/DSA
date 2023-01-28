 #include<iostream>
using namespace std;
#define Max 10
int arr[10] = { 2,4,3,9,1,4,8,7,5,6 };
int partition(int low, int high) {
	int i = low + 1;
	int j = high;
	int pivot = arr[low];
	int temp = 0;

	do
	{
		while (arr[i]<=pivot)
		{

			i++;
		}

		while (arr[j]>pivot)
		{
			j--;
		}
		if (i < j) {
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}

	} while (i<j);
	temp = arr[low];
	arr[low] = arr[j];
	arr[j] = temp;
	return j;
}
void quick_Sort( int low, int high) {
	int partition_Index;
		if(low<high) {
		partition_Index = partition(low, high);
		quick_Sort(low, partition_Index - 1);// sort left subarray 
		quick_Sort(partition_Index + 1, high);// sort right subarray

	}
}
void dispaly() {
	for (int i = 0; i < Max; i++)
	{
		cout << arr[i] << " ";
	}
}

int main() {
	quick_Sort(0, Max-1);
	dispaly();
}