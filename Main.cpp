#include "FileGenerator.h"
#include "SimilarString.h"
#include <iostream>
#include <chrono> //time measurement

using namespace std;

void main()
{
	cout << "[[ File generation ]]\n";
	auto time_start = chrono::steady_clock::now();
	GenerateFile(4, 5, 100000);
	auto time_end = chrono::steady_clock::now();
	cout << "Done in: " << chrono::duration_cast<chrono::milliseconds>(time_end - time_start).count() << "ms\n";
	
	cout << "[[ File reading ]]\n";
	time_start = chrono::steady_clock::now();
	SimilarString A;
	A.ReadFile("input.txt");
	time_end = chrono::steady_clock::now();
	cout << "Done in: " << chrono::duration_cast<chrono::milliseconds>(time_end - time_start).count() << "ms\n";

	//for (auto& i : A.data)
	//{
	//	cout << i << endl;
	//}
	//cout << "String to search: ";

	cout << "[[ Searching a string ]]\n";
	string target = A.data[3];
	int k = 3;

	cout << "Target string to search: " << target << "\nMaximum number of changes allowed: " << k << endl;
	//cin >> target;
	time_start = chrono::steady_clock::now();
	auto strings = A.FindSimilar(target, k);
	time_end = chrono::steady_clock::now();
	cout << "Done in: " << chrono::duration_cast<chrono::milliseconds>(time_end - time_start).count() << "ms\n";
	if (strings.size() < 15)
	{
		cout << "Output: \n";
		for (auto& i : strings)
			cout << i << endl;
	}
	else
	{
		cout << "Found more than 15 strings, displaying first 15: \n";
		cout << "Output: \n";
		for (int i = 0; i < 15; i++)
			cout << strings[i] << endl;
	}
	
}