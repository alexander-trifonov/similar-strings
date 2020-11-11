#pragma once
//Goal - to remember how to work with headers, generators, multithreading

#include <string>



//https://isocpp.org/files/papers/n3551.pdf

//* int lenmin - min lenght of a generated string
//* int lenmax - max length of a generated string
//* int amount - amount of generated strings
//* filename = "input.txt" - file name where output will be generated
void GenerateFile(unsigned short int lenmin = 3, unsigned short int lenmax = 7, unsigned int amount = 1000, std::string filename = "input.txt");



