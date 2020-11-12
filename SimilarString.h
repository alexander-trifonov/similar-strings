#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <filesystem>
#include <stdlib.h>

#include <iostream>

using namespace std;

class SimilarString
{
public:
	vector<string> data;

	SimilarString() {};

	void ReadFile(string filepath)
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
			data.push_back(buffer);
		}
	};


	//http://repo.ssau.ru/bitstream/Informacionnye-tehnologii-i-nanotehnologii/Algoritm-nechetkogo-poiska-v-bazah-dannyh-i-ego-prakticheskaya-realizaciya-64172/1/paper%20340_1885-1889.pdf

	int m(string& a, string& b)
	{
		if (a[a.length() - 1] == b[b.length() - 1])
			return 0;
		else
			return 1;
	}

	unsigned short int distLev(string& a, string& b)
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

	// target - string to search
	// k - max k changes to transform the target to the file's string
	vector<string> FindSimilar(string& target, int k)
	{
		vector<string> res;
		unsigned short int dist;
		for (string& data_string : this->data)
		{
			if (distLev(target, data_string) <= k)
				res.push_back(data_string);
		}
		return res;
	}
};