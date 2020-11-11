#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <filesystem>

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
	
	vector<string> FindSimilar(string& substr)
	{

	}
};