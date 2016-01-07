#include <iostream>
#include <cstdlib>
#include <array>
#include <iomanip>

using namespace std;

int getMax(int a[], int n);
void radixSort(int a[], int n);
void countSort(int a[], int n, int exp);

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

	cout << "Before radix sort: " << endl;
	for (int i = 0; i < asize; i++)
	{
		cout << a[i] << ", ";
	}
	cout << endl;
	cout << endl;

	radixSort(a, asize);

	cout << "After radix sort: " << endl;
	for (int i = 0; i < asize; i++)
	{
		cout << a[i] << ", ";
	}

	return 0;
}

// A function to get maximum value in arr[]
int getMax(int a[], int n)
{
	int mx = a[0];
	for (int i = 1; i < n; i++)
		if (a[i] > mx)
			mx = a[i];
	return mx;
}

void radixSort(int a[], int n)
{
	int m = getMax(a, n);

	// Do counting sort for every digit
	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(a, n, exp);
}

// A function to do counting sort of arr[] according to the digit represented by exp.
void countSort(int a[], int n, int exp)
{
	int *output = new int[n]; 
	int i, count[10] = { 0 };

	// Store count of occurrences in count[]
	for (i = 0; i < n; i++)
		count[(a[i] / exp) % 10]++;

	// Change count[i] so that count[i] now contains actual
	//  position of this digit in output[]
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Build the output array
	for (i = n - 1; i >= 0; i--)
	{
		output[--count[(a[i] / exp) % 10]] = a[i];
		//count[(a[i] / exp) % 10]--;
	}

	// Copy the output array to arr[], so that arr[] now
	// contains sorted numbers according to current digit
	for (i = 0; i < n; i++)
		a[i] = output[i];

	delete[] output;
}
