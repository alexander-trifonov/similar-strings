#pragma once
#include <string>
#include <vector>

using namespace std;

class SimilarString
{
public:
	vector<string> data;

	SimilarString() {};

	// Read file in this.data;
	void ReadFile(string filepath);

	// Returns 0, if a[-1]==b[-1], otherwise 1;
	int m(string& a, string& b);

	// Resursive variant from wikipedia
	unsigned short int distLev(string& a, string& b);

	// Implemented through A[][] matrix
	unsigned short int distLev2(string& a, string& b);

	// One-dimensional array
	unsigned short int distLev3(string& a, string& b);
	
	//https://en.wikipedia.org/wiki/Levenshtein_distance
	// target - string to search
	// k - max k changes to transform the target to the file's string
	vector<string> FindSimilar(string& target, int k);
};