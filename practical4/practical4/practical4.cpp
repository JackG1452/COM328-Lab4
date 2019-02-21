//================================================================================
// Name        : practical4.cpp
// Author      : a.mccaughey@ulster.ac.uk
// Version     : 1.0
// Description : practical 4 test program to utilise sort algorithms
//================================================================================

#include <string> // used to access string type
#include <cctype>
#include <ctime> // used to access clock_t and clock()

#include "Array.h"
#include "Sorter.h"

using namespace std;

// Test relative sort performances when sorting same random 
// number sequence of specified size. 
void testPerformance(int size) {
  // create a Sorter for each sort algorithm ensuring each
  // contain the same random numbers. Use of Sorter copy
  // constructor is one way to ensure this!!
  
	Sorter<int> qsorter(1000); // create quick sorter as first sorter
	qsorter.fillRandom(); // fill it with random numbers

	Sorter<int> msorter(qsorter); // make merge sorter a duplicate of quick sorter
	Sorter<int> isorter(qsorter); // make insertion sorter a duplicate of quick sorter
	Sorter<int> ssorter(qsorter); // make selection sorter a duplicate of quick sorter

  // For each Sorter start clock, call relevant sort algorithm, 
  // call clock again, print results

	clock_t start, start1, finish, finish1;

	// time sort of random data
	start = clock();

	//calling quick sort algorithm for unsorted data
	qsorter.quickSort();

	//call a sorter sort method
	finish = clock();

	//calling quick sort algorithm for sorted data
	qsorter.quickSort();

	// time sort of sorted data
	start1 = clock();
	// call same sort method again
	finish1 = clock();

	// Calculate the time taken for random sort and time taken for sorted sort

	cout << "Quick Sort size = " << size << " Time taken random/sorted " << finish << "/" << finish1 << endl;
  // Note:Sorting very large data sets may cause quicksort to run out
  // of stack space and crash program as recursive overhead is too great.

	
}

// Determine the most frequent word in the supplied text file 'words.txt'
// print the word and its frequency
void wordFrequency() {

}



// Main method.
int main() {

	testPerformance(10000);

	// ---------------------------------------------------
	cout << endl << "Press enter to quit";
	cin.get();
	return 0;
}