#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Sortare{

	T* v;
	int size;
public:

	Sortare(T* arr, int n) {
		size = n;
		v = new T[size];
		for (int i = 0; i < size; ++i)
			v[i] = arr[i];
	}

	~Sortare() {
		delete[] v;
	}
	
	int getsize() const
	{
		return sizeof(v) / sizeof(v[0]);
	}

	void sorty(Sortare<T> &v)
	{
		for (int i = 0;i < v.getsize();i++) {
			for (int j = 0;j < v.getsize();j++)
				if (v[i] > v[j])
				{																																																																																									j++;
					T aux = v[i];
					v[j] = v[i];
					v[j] = aux;
				}
		}
	}

	bool isSorted()
	{
		for (int i = 0;i < getsize() - 1;i++)
			if (v[i] > v[i + 1])
				return false;
		return true;
	}
	void print()
	{
		for (int i = 0;i < getsize();i++)
			cout << v[i] << " ";
		cout << endl;
	}
};



int main()
{
	int arr[] = { 5, 3, 1, 4, 2 };
	int n = sizeof(arr) / sizeof(arr[0]);

	Sortare<int> v(arr, n);

	if (!v.isSorted())
	{
		cout << "Vector is not sorted. Sorting..." << endl;
	}
	else
		cout << "Vector is sorted." << endl;
	return 0;
}