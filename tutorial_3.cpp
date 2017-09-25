// Student name: ZHOU Zhenghao	
// Student ID  : 54381018

// Submission is NOT required for this tutorial.


#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
	Part-1:	Sorting and binary search
*/
void sort(double d[], int n)
{
	int m = 0;
	double temp;
	while (m < n) {
		for (int i = m; i >= 0; i--) {
			if (d[i] > d[i + 1]) {
				temp = d[i];
				d[i] = d[i + 1];
				d[i + 1] = temp;
			}
			else
				break;
		}
		m++;
	}// sort the input array into ascending order
	
}

int getInterval(const double d[], int n, double x)
{
	int index;
	if (x < d[0]) {
		index = -1;
	}
	else if (x > d[n - 1]) {
		index = n - 1;
	}
	else
		for (int m = 0; m < n-1; m++) {
			if (d[m]<= x) {
				if (x < d[m + 1]) {
					index = m;
					break;
				}
			}
		}
	// Preconditions: n >= 1 and d[] is sorted in ascending order
	//                numbers in d[] are distinct

	// x belongs to interval i if d[i] <= x < d[i+1].
	// By definition: 
	//     if x < d[0], then x belong to interval -1
	//     if x >= d[n-1], then x belong to interval n-1

	// Implement this function using the binary search approach.

	
	return index; // dummy return statement
}

/*
	Part-2: Circular array.
*/

int getMinLoc(const double d[], int n)
{	
	double temp=d[0];
	int index;
	for (int i = 0; i < n; i++) {
		if (temp >= d[i]) {
			temp = d[i];
			index = i;
		}
	}
	
	// Preconditions: 1. d[] is a circular array, and n > 1
	//                2. all numbers in d[] are distinct
	//                3. numbers are arranged in ascending order (circularly)

	// Return the location of the smallest number in d[].
	// Implement this function using the binary search approach.

	
	return index;  // dummy return statement
}


// functions prepared for you ---------------------------------------------------
void rotate(double d[], int n)
{
	// Rotate the elements in the array d[0..n-1] by 1 position.

	double temp = d[n-1];
	for (int i = n-2; i >= 0; i--)
		d[i+1] = d[i];

	d[0] = temp;
}

void printArray(const double d[], int n)
{
	cout << "Input array : n = " << n << endl;
	for (int i = 0; i < n; i++)
	{
		if (i > 0 && i % 10 == 0)
			cout << endl;
		cout << setw(6) << d[i] << ", ";  // setw(6) : set the field width to 6 chars
	}
	cout << endl << endl;
}

int main()
{	
	srand((unsigned)time(NULL));  
	
	int n = 20;
	double *d = new double[n];

	for (int i = 0; i < n; i++)
		d[i] = rand() / 100.0;

	cout << "Part-1" << endl << endl;
	
	sort(d, n);
	printArray(d, n);

	double x;
	int interval;

	for (int i = 0; i < 6; i++)
	{
		x = rand() / 100.0;
		interval = getInterval(d, n, x);
		if (interval < 0)
			cout << setw(6) << x << " is within the interval [-infinity, " << setw(6) << d[0] << "]" << endl;
		else if (interval >= n-1)
			cout << setw(6) << x << " is within the interval [" << setw(6) << d[n-1] << ", infinity]" << endl;
		else
			cout << setw(6) << x << " is within the interval [" << setw(6) << d[interval] << ", "
			     << setw(6) << d[interval+1] << "]" << endl;		
	}

	cout << endl << "Second test case:" << endl;
	n = 1;
	printArray(d, n);
	interval = getInterval(d, n, x);
	if (interval < 0)
		cout << setw(6) << x << " is within the interval [-infinity, " << setw(6) << d[0] << "]" << endl;
	else if (interval >= n-1)
		cout << setw(6) << x << " is within the interval [" << setw(6) << d[n-1] << ", infinity]" << endl;
	else
		cout << setw(6) << x << " is within the interval [" << setw(6) << d[interval] << ", "
			 << setw(6) << d[interval+1] << "]" << endl;


	cout << endl << "----------------------------------------" << endl;
	cout << "Part-2" << endl << endl;
	
	n = 20;
	printArray(d, n);

	cout << "Index of smallest element = " << getMinLoc(d, n) << endl << endl;	
	
	cout << "++++++++++++++++++++++++++" << endl << endl;
	rotate(d, n);
	printArray(d, n);
	cout << "Index of smallest element = " << getMinLoc(d, n) << endl;
	
	cout << "++++++++++++++++++++++++++"  << endl << endl;

	for (int j = 0 ; j < n/2 + 1; j++)
		rotate(d, n);

	printArray(d, n);
	cout << "Index of smallest element = " << getMinLoc(d, n) << endl;

	cout << "++++++++++++++++++++++++++"  << endl << endl;
	for (int j = 3; j < n / 2; j++)
		rotate(d, n);

	printArray(d, n);
	cout << "Index of smallest element = " << getMinLoc(d, n) << endl;
	
	system("pause");
	return 0;
}