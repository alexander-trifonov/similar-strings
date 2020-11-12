#include "SimilarString.h"
#include <string>
#include <fstream>
#include <vector>
#include <filesystem>
#include <stdlib.h>

#include <iostream>

using namespace std;

void SimilarString::ReadFile(string filepath)
{
	ifstream if_stream(filepath, ios::binary);
	//Good way to load whole file (not necessary in that case, but was intresting to research)
	//http://www.cplusplus.com/reference/string/string/string/ 
	//https://stackoverflow.com/questions/524591/performance-of-creating-a-c-stdstring-from-an-input-iterator - method 2, but I changed how file size is calculating because tellg isn't adviced to use		
	//C++17 supports file_size method
	/*
	filesystem::path _path(filepath);
	auto f_size = filesystem::file_size(_path);
	vector<char> buffer(f_size);
	if_stream.read(&buffer[0], f_size);
	if_stream.close();
	return string(&buffer[0], f_size);
	*/

	string buffer;
	while (getline(if_stream, buffer, '\n'))
	{
		buffer = buffer.substr(0, buffer.find("\r"));
		data.push_back(buffer);
	}
	if_stream.close();
};

int SimilarString::m(string& a, string& b)
{
	if (a[a.length() - 1] == b[b.length() - 1])
		return 0;
	else
		return 1;
}

unsigned short int SimilarString::distLev(string& a, string& b)
{
	auto a_len = a.length();
	auto b_len = b.length();
	if (std::min(a_len, b_len) == 0)
	{
		return std::max(a_len, b_len);
	}
	else
	{
		return std::min(
			{ // http://www.cplusplus.com/reference/initializer_list/initializer_list/
			distLev(a, b.substr(0, b_len - 1)) + 1, // deletion
			distLev(a.substr(0, a_len - 1), b) + 1, // inserting
			distLev(a.substr(0, a_len - 1), b.substr(0, b_len - 1)) + m(a, b) // matched/replacing
			}
		);
	}
}

unsigned short int SimilarString::distLev2(string& a, string& b)
{
	unsigned short int a_len = a.length();
	unsigned short b_len = b.length();

	vector<vector<unsigned int> > d(a_len + 1, vector<unsigned int>(b_len + 1));
	d[0][0] = 0;
	for (unsigned int i = 1; i <= a_len; ++i) d[i][0] = i;
	for (unsigned int i = 1; i <= b_len; ++i) d[0][i] = i;

	for (unsigned int i = 1; i <= a_len; ++i)
		for (unsigned int j = 1; j <= b_len; ++j)
			d[i][j] = std::min(
				{
					d[i][j - 1] + 1,
					d[i - 1][j] + 1,
					d[i - 1][j - 1] + (a[i - 1] == b[j - 1] ? 0 : 1)
				});
	return d[a_len][b_len];
}

// target - string to search
// k - max k changes to transform the target to the file's string
vector<string> SimilarString::FindSimilar(string& target, int k)
{
	vector<string> res;
	unsigned short int dist;
	for (string& data_string : this->data)
	{
		cout << data_string << endl;
		auto dist = distLev2(target, data_string);
		cout << data_string << endl << " " << target << " " << dist<< endl;
		if ( dist <= k)
			res.push_back(data_string);
	}
	return res;
}