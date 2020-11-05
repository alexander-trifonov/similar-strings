#include <fstream>
#include <random>

using namespace std;

// [ Single-thread variant ]

void GenerateFile(unsigned short int lenmin = 3, unsigned short int lenmax = 7, unsigned int amount = 1000, string filename = "input.txt")
{
	random_device rd; //uses device or smth with low amount of entropy to generate a value, so use only for seed
	mt19937 engine(rd());
	//uniform_int_distribution<unsigned __int8> distChar(0, 25); //int8_t, and uint8_t are not allowed :(
	uniform_int_distribution<unsigned short int> distChar(0, 25); //|abcdefghijklmnopqrstuvwxyz|==26 
	uniform_int_distribution<unsigned short int> distLength(lenmin, lenmax); //for string's length; probably should use somthing simplier
	ofstream f_stream(filename, ofstream::trunc);

	unsigned short int length; //out of loop to not waste time on the initialization
	int a = int('a');
	string _string;
	for (unsigned int i = 0; i < amount; i++)
	{
		length = distLength(engine);
		_string.clear();
		for (unsigned short int j = 0; j < length; j++)
		{
			_string += char(a + distChar(engine));
		}
		f_stream << _string << endl;
	}
	f_stream.close();
}

// [ Multithread variant ]
// Summary: Multithreading only worsten the time in 1.5-2 times because of low calculating processes, but lots of tension on writing in the file

//void GenerateFile(unsigned short int lenmin = 3, unsigned short int lenmax = 7, unsigned int amount = 1000, string filename = "input.txt")
//{
//	random_device rd; //uses device or smth with low amount of entropy to generate a value, so use only for seed
//	mt19937 engine(rd());
//	//uniform_int_distribution<unsigned __int8> distChar(0, 25); //int8_t, and uint8_t are not allowed :(
//	uniform_int_distribution<unsigned short int> distChar(0, 25); //|abcdefghijklmnopqrstuvwxyz|==26 
//	uniform_int_distribution<unsigned short int> distLength(lenmin, lenmax); //for string's length; probably should use somthing simplier
//	ofstream f_stream(filename, ofstream::trunc);
//
//#pragma omp parallel
//	{
//		unsigned short int length;		
//#pragma omp for
//		for (int i = 0; i < amount; i++) //omp for doesn't support unsigned
//		{
//			length = distLength(engine);
//			string _string;
//			for (unsigned short int j = 0; j < length; j++)
//			{
//				_string += char(int('a') + distChar(engine));
//			}
//#pragma omp critical
//			{
//				f_stream << _string << endl;
//			}
//		}
//	}
//	//maybe need a barrier
//	f_stream.close();
//}