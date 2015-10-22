#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		cout << "Correct usage: flipbyte.exe <0-255>" << endl;
		return 1;
	}
	string numberAsString = argv[1];
	int intNumber;

	try
	{
		intNumber = stoi(numberAsString);
	}
	catch (const invalid_argument& e)
	{
		cout << "Correct usage: flipbyte.exe <0-255>" << endl;
		return 1;
	}
	catch (const out_of_range& e)
	{
		cout << "Correct usage: flipbyte.exe <0-255>" << endl;
		return 1;
	}

	if ((intNumber < 0) || (intNumber > 255))
	{
		cout << "Number " << intNumber << " is out of range [0..255]" << endl;
		return 1;
	}

	unsigned char number = static_cast<char>(intNumber);
	unsigned char reversedNumber = 0;
	int bitNumber = 8;
	for (int i = 0; i < bitNumber; i++)
	{
		reversedNumber <<= 1;
		reversedNumber |= ((number >> i) & 0x01);
	}
	cout << +reversedNumber << endl;
	return 0;
}