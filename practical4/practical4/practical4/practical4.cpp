
//================================================================================
// Name        : practical4.cpp
// Author      :
// Version     : 1.0
// Description : practical 4 test program to utilise sort algorithms
//================================================================================

#include <string> // used to access string type
#include <cctype>
#include <ctime> // used to access clock_t and clock()

#include "Array.h"
#include "Sorter.h"

using namespace std;

// Test relative sort performances when sorting same
// random and sorted number sequence.
void testPerformance(int size) {
	// create a Sorter for each sort algorithm ensuring each
	// contain the same random numbers. Use of Sorter copy
	// constructor is one way to ensure this!!
	Sorter<int> qsorter(size); // create quick sorter as first sorter
	qsorter.fillRandom(size*2); // fill it with random numbers

	Sorter<int> msorter(qsorter); // make merge sorter a duplicate of quick sorter
	Sorter<int> isorter(qsorter); // make insertion sorter a duplicate of quick sorter
	Sorter<int> ssorter(qsorter); // make selection sorter a duplicate of quick sorter

	// For each Sorter start clock, call relevant sort algorithm, 
	// call clock again, print results
	clock_t start, start1, finish, finish1;

	//QUICK SORT TEST

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


	//MERGE SORT TEST
	// time sort of random data
	start = clock();
	//calling quick sort algorithm for unsorted data
	msorter.mergeSort();
	//call a sorter sort method
	finish = clock();

	//calling quick sort algorithm for sorted data
	msorter.mergeSort();
	// time sort of sorted data
	start1 = clock();
	// call same sort method again
	finish1 = clock();

	// Calculate the time taken for random sort and time taken for sorted sort
	cout << "Merge Sort size = " << size << " Time taken random/sorted " << finish << "/" << finish1 << endl;


	//INSERTION SORT TEST
	// time sort of random data
	start = clock();
	//calling quick sort algorithm for unsorted data
	isorter.insertionSort();
	//call a sorter sort method
	finish = clock();

	//calling quick sort algorithm for sorted data
	isorter.insertionSort();
	// time sort of sorted data
	start1 = clock();
	// call same sort method again
	finish1 = clock();

	// Calculate the time taken for random sort and time taken for sorted sort
	cout << "Insertion Sort size = " << size << " Time taken random/sorted " << finish << "/" << finish1 << endl;


	//SELECTION SORT TEST
	// time sort of random data
	start = clock();
	//calling quick sort algorithm for unsorted data
	ssorter.selectionSort();
	//call a sorter sort method
	finish = clock();

	//calling quick sort algorithm for sorted data
	ssorter.selectionSort();
	// time sort of sorted data
	start1 = clock();
	// call same sort method again
	finish1 = clock();

	// Calculate the time taken for random sort and time taken for sorted sort
	cout << "Selection Sort size = " << size << " Time taken random/sorted " << finish << "/" << finish1 << endl;

	// Note:Sorting very large data sets may cause quicksort to run out
	// of stack space and crash program as recursive overhead is too great.
	cout << "" << endl;
}


// Determine the most frequent word in the supplied text file 'words.txt'
// print the word and its frequency
void wordFrequency() {
	Sorter<string> words;

	// complete method by loading content of test.txt into 'words' sorter
	// defined above (use the sorter loadFile method). Sort the content by
	// (calling a sorter sort methd (any will do), then extract the sorted
	// array from the sorter (use the sorter getElements() method). Finally
	// loop through the sorted array and determine the most frequently occuring word
	// print the word and the number of occurences

	words.loadFile("words.txt");
	words.quickSort();
	words.getElements();

	int value = 1;
	int pos = 0;
	int biggest = 1;

	for (int i = 0; i < words.capacity() - 1; ++i)
	{
		if (words.getElements()[i] == words.getElements()[i+1])
		{
			value ++;
		}
		else
		{
			value = 0;
		}
		if (biggest < value)
		{
			biggest = value;
			pos = i;
		}
		
	}
	cout << "Most frequent word = " << words.getElements()[pos] << " \nIt occurred " << biggest << " times" << endl;
}



// Main method.
int main() {
	//initialise the random number generator
	srand((unsigned)time(NULL));

	// q1 testPerformance
	//testPerformance(10000);
	// create a loop to call with values e.g. 10000,15000,2000
	/*int size = 5000;
	for (int i = 0; i < 4; i++)
	{
		testPerformance(size);
		size += 5000;
	}*/

	// call the word frequency method to solve q2
	wordFrequency();
	// ---------------------------------------------------
	cout << endl << "Press enter to quit";
	cin.get();
	return 0;
}
