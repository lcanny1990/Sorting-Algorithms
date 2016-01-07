#include <iostream>
#include <cstdlib>
#include <array>
#include <iomanip>

using namespace std;

void mergeSort(int a[], int size);
void MergeSort(int a[], int tempA[], int left, int right);
void merge(int a[], int tempA[], int left, int right, int R_end);


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

	cout << "Before merge sort: " << endl;
	for (int i = 0; i < asize; i++)
	{
		cout << a[i] << ", ";
	}
	cout << endl;
	cout << endl;

	mergeSort(a, asize);

	cout << "After merge sort: " << endl;
	for (int i = 0; i < asize; i++)
	{
		cout << a[i] << ", ";
	}

	return 0;
}

void mergeSort(int a[], int size)
{
	int *tempA = new int[size];
	MergeSort(a, tempA, 0, (size - 1));
	delete[]tempA;
}

void MergeSort(int a[], int tempA[], int left, int right)
{
	if (left < right)
	{
		int center = (left + right) / 2;
		MergeSort(a, tempA, left, center);
		MergeSort(a, tempA, center + 1, right);
		merge(a, tempA, left, center + 1, right);
	}
}

void merge(int a[], int tempA[], int left, int right, int R_end)
{
	int L_end = right - 1;
	int tmp_pos = left;
	int num_elem = R_end - left + 1;

	while (left <= L_end && right <= R_end)
	{
		if (a[left] <= a[right])
			tempA[tmp_pos++] = a[left++];
		else
			tempA[tmp_pos++] = a[right++];
	}
	while (left <= L_end)
	{
		tempA[tmp_pos++] = a[left++];
	}
	while (right <= R_end)
	{
		tempA[tmp_pos++] = a[right++];
	}

	for (int i = 0; i < num_elem; ++i, --R_end)
	{
		a[R_end] = tempA[R_end];
	}


}
