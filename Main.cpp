#include "FileGenerator.h"
#include "SimilarString.h"
#include <iostream>
#include <chrono> //time measurement

using namespace std;

void main(int argc, char* argv[])
{
	chrono::steady_clock::time_point time_start;
	chrono::steady_clock::time_point time_end;
	cout << "[[ File generation ]]\n";
	char answer;
	string filepath;
	

	if (argc > 1)
	{
		filepath = argv[1];
	}
	else
	{
		cout << "Generate a new file, named 'input.txt'? y/n: ";
		cin >> answer;
		if (answer == 'y')
		{
			time_start = chrono::steady_clock::now();
			GenerateFile(4, 5, 10000000);
			time_end = chrono::steady_clock::now();
			cout << "Done in: " << chrono::duration_cast<chrono::milliseconds>(time_end - time_start).count() << "ms\n";
			filepath = "input.txt";
		}
		else
			if (answer == 'n')
			{
				cout << "Write path to the file: ";
				cin >> filepath;
			}
	}
		
	
	
	cout << "[[ File reading ]]\n";
	time_start = chrono::steady_clock::now();
	SimilarString A;
	A.ReadFile(filepath);
	time_end = chrono::steady_clock::now();
	cout << "Done in: " << chrono::duration_cast<chrono::milliseconds>(time_end - time_start).count() << "ms\n";

	cout << "[[ Searching a string ]]\n";
	string target;
	int k = 3;
	if (argc > 2)
		target = argv[2];
	else
	{
		cout << "To help you, you can write one of these first strings in the file:" << endl;
		cout << "* " << A.data[1] << endl;
		cout << "* " <<  A.data[2] << endl;
		cout << "Enter string to search: ";
		cin >> target;
	}

	cout << "Target string to search: " << target << "\nMaximum number of changes allowed: " << k << endl;
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