//============================================================================
// Name        : BubbleSort.cpp
// Author      : Larry
// Date        : Apr 2007
// Version     :
// Based on... : an original idea by 'C++ How To Program'
// Description : Bubble sort in C++, Ansi-style
//============================================================================
/* Sorts the values of the 10 -element array 'a' into ascending
 * order. The technique used is called a bubble sort or sinking
 * sort because the smaller values gradually "bubble" their way
 * upward to the top of the array like air bubbles rising in
 * water, while the larger values sink to the bottom of the array.
 * The technique is to make several passes through the array. On
 * each pass, successive pairs of elements are compared. If a pair
 * is in increasing order (or the values are identical), we leave
 * the values as they are. If a pair is in decreasing order, their
 * values are swapped in the array.
 */
#include <iostream>	// cin, cout
#include <iomanip>	// setiosflags(), setw().
#include <stdlib.h>	// rand(), srand()
#include <ctime>	// time()

using std::cout;
using std::setw;
using std::endl;

int main()
{
	const int arraySize = 50000;
	const int range = 1000;
	// randomly populate array with ints between 0 and 999
	int a[arraySize];
	int i, hold;
	srand(time(0));
	for (i = 0; i < arraySize; i++)
		a[i] = rand() % range;

	bool swaps;

	cout << "Data items in original order\n";

	for (i = 0; i < arraySize; i++) {
		if ( i % 10 == 0 )	// display 10 numbers per line
			cout << "\n";
		cout << setw(4) << a[i];
	}

	for (int pass = 0; pass < arraySize - 1; pass++) {	// passes

		// after first pass the highest number is in the last
		// element. After second pass the two highest numbers are
		// in the last two elements of the array and so on.
		// Therefore after each pass one less comparison than
		// before is necessary.
		swaps = false;
		for (i = 0; i < arraySize - (1 + pass); i++) // one pass

			if (a[i] > a[i + 1]) {	// one comparison
				hold = a[i]; 		// one swap
				a[i] = a[i + 1];
				a[i + 1] = hold;
				swaps = true;
			}
		// if no swaps on this pass, do no more passes.
		if (swaps == false)
			break;
	}


	cout << "\nData items in ascending order\n";

	for (i = 0; i < arraySize; i++) {
		if ( i % 10 == 0 )	// display 10 numbers per line
			cout << "\n";
		cout << setw(4) << a[i];
	}

	cout << endl;
	return 0;
}
