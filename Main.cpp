#include "FileGenerator.h"
#include "SimilarString.h"
#include <iostream>
#include <chrono> //time measurement

using namespace std;

void main()
{
	cout << "File is generating..." << endl;
	auto time_start = chrono::steady_clock::now();
	GenerateFile(4, 5, 100);
	auto time_end = chrono::steady_clock::now();
	cout << "File has been generated for " << chrono::duration_cast<chrono::milliseconds>(time_end - time_start).count() << " milliseconds\n";
	
	cout << "File is reading..." << endl;
	time_start = chrono::steady_clock::now();
	SimilarString A;
	A.ReadFile("input.txt");
	time_end = chrono::steady_clock::now();
	cout << "File has been read for " << chrono::duration_cast<chrono::milliseconds>(time_end - time_start).count() << " milliseconds\n";

	//for (auto& i : A.data)
	//{
	//	cout << i << endl;
	//}
	//cout << "String to search: ";
	string target = A.data[3];
	
	cout << "Target string to search: " << target << endl;
	//cin >> target;


}