
#include <iostream>
#include <cstdlib>
#include <array>
#include <iomanip>

using namespace std;

void insertSort(int a[], int size)
{
	int current = 0;
	int index = 0;

	for (int i = 1; i <= size - 1; i++)
	{
		current = a[i];
		index = i;

		while (index > 0 && a[index - 1] > current)
		{
			a[index] = a[index - 1];
			index--;
		}

		a[index] = current;

	}
}


int main(int argc, char* argv[])
{
	const int asize = 8;
	int a[asize];
	a[0] = 5;
	a[1] = 1;
	a[2] = 6;
	a[3] = 2;
	a[4] = 8;
	a[5] = 9;
	a[6] = 0;
	a[7] = 4;

	cout << "Before insertion sort: " << endl;
	for (int i = 0; i < asize; i++)
	{
		cout << a[i] << ", ";
	}
	cout << endl;
	cout << endl;
	
	insertSort(a, asize);

	cout << "After insertion sort: " << endl;
	for (int i = 0; i < asize; i++)
	{
		cout << a[i] << ", ";
	}

	return 0;
}
