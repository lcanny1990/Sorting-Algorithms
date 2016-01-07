//quick sort uses the Median 3 function to find the pivot

#include <iostream>
#include <cstdlib>
#include <array>
#include <iomanip>

using namespace std;

void quickSort(int a[], int size);
void quickSort2(int a[], int left, int right);
int median3(int a[], int left, int right);

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

	cout << "Before quick sort: " << endl;
	for (int i = 0; i < asize; i++)
	{
		cout << a[i] << ", ";
	}
	cout << endl;
	cout << endl;

	quickSort(a, asize);

	cout << "After quick sort: " << endl;
	for (int i = 0; i < asize; i++)
	{
		cout << a[i] << ", ";
	}

	return 0;
}

void quickSort(int a[], int size)
{
	quickSort2(a, 0, size - 1);
}

void quickSort2(int a[], int left, int right)
{
	if (right - left >= 2)
	{
		int pivot = median3(a, left, right);
		int i = left;
		int j = right - 1;


		for (; ; )
		{
			while (a[++i] < pivot) {}
			while (pivot < a[--j]) {}

			if (i < j)
				std::swap(a[i], a[j]);
			else
				break;
		}


		std::swap(a[i], a[right - 1]);

		quickSort2(a, left, i - 1);
		quickSort2(a, i + 1, right);

	}
	else if (right - left == 1)
	{
		if (a[left] > a[right])
			std::swap(a[left], a[right]);
	}


}

int median3(int a[], int left, int right)
{
	int center = (left + right) / 2;

	if (a[center] < a[left])
		std::swap(a[left], a[center]);
	if (a[right] < a[left])
		std::swap(a[left], a[right]);
	if (a[right] < a[center])
		std::swap(a[center], a[right]);

	std::swap(a[center], a[right - 1]);
	return a[right - 1];
}
