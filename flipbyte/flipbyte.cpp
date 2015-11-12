#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

const auto BIT_NUMBER = std::numeric_limits<uint8_t>::digits;
const auto MIN_VALUE = std::numeric_limits<uint8_t>::min();
const auto MAX_VALUE = std::numeric_limits<uint8_t>::max();

uint8_t StringToUint(const string & numberAsString);
uint8_t FlipUint(uint8_t number);

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		cout << "Usage: flipbyte.exe <" + to_string(MIN_VALUE) + ", " + to_string(MAX_VALUE) + ">" << endl;
		return 1;
	}
	string numberAsString = argv[1];

	try
	{
		uint8_t originNumber = StringToUint(numberAsString);
		int flippedNumber = FlipUint(originNumber);
		cout << to_string(flippedNumber) << endl;
	}
	catch (const invalid_argument & e)
	{
		cout << "Error: argument must be a number" << endl;
		return 1;
	}
	catch (const out_of_range & e)
	{
		cout << "Error: number must be in range <" + to_string(MIN_VALUE) + ", " + to_string(MAX_VALUE) + ">" << endl;
		return 1;
	}
	return 0;
}

uint8_t StringToUint(const string & numberAsString)
{
	int intNumber = MIN_VALUE;
	uint8_t number = MIN_VALUE;
	intNumber = stoi(numberAsString);
	if ((intNumber < MIN_VALUE) || (intNumber > MAX_VALUE))
	{
		throw std::out_of_range("out of range");
	}
	else
	{
		number = static_cast<uint8_t>(intNumber);
	}

	return number;
}

uint8_t FlipUint(uint8_t number)
{
	uint8_t flippedNumber = 0;
	for (auto i = 0; i < BIT_NUMBER; i++)
	{
		flippedNumber <<= 1;
		flippedNumber |= ((number >> i) & 0x01);
	}
	return flippedNumber;
}