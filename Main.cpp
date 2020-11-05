#include "FileGenerator.h"
#include <iostream>
#include <chrono> //time measurement
#include <omp.h>
using namespace std;

void main()
{
	cout << "File generating..." << endl;
	auto time_start = chrono::steady_clock::now();
	GenerateFile(4, 5, 1000);
	auto time_end = chrono::steady_clock::now();
	cout << "File has been generated for " << chrono::duration_cast<chrono::milliseconds>(time_end - time_start).count() << " milliseconds\n";

	cout << "String to search: ";
	string target;
	cin >> target;


}