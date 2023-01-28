#include<iostream>
using namespace std;

template <class T>

class vector {
public:
	T a ;
	int Size;

	T Sum() {
		T d = 0;
		for (int i = 0; i < Size; i++)
		{
			d = a + a;
			cout << d << endl;
		}
		return d;
	}
};

int main() {
	vector<int> v1;
	v1.Size = 2.33;
	v1.a = 33.32;
	int S1 = v1.Sum();
	cout << "Float" << endl;
	vector<float> v2;
	v2.Size = 2.33;
	v2.a = 33.32;
	float S2 = v2.Sum();
}