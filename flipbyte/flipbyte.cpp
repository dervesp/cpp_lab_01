#include <iostream>
#include <fstream>
#include <string>

using namespace std;

typedef uint8_t Number;
const auto BIT_NUMBER = 8;
const auto MIN_VALUE = 0;
const auto MAX_VALUE = pow(2, BIT_NUMBER) - 1;

enum class ParseNumberError {
	NoError,
	NotANumber,
	OutOfRange
};

Number ParseNumberFromString(const string numberAsString, ParseNumberError & error);
string GetParseNumberErrorAsString(const ParseNumberError & error);
Number FlipNumber(const Number & number);

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		cout << "Usage: flipbyte.exe <" + to_string(MIN_VALUE) + ", " + to_string(MAX_VALUE) + ">" << endl;
		return 1;
	}
	string numberAsString = argv[1];

	ParseNumberError error = ParseNumberError::NoError;
	Number originNumber = ParseNumberFromString(numberAsString, error);
	if (error != ParseNumberError::NoError)
	{
		cout << GetParseNumberErrorAsString(error) << endl;
		return 1;
	}
	else
	{
		int flippedNumber = FlipNumber(originNumber);
		cout << to_string(flippedNumber) << endl;
	}
	return 0;
}

Number ParseNumberFromString(const string numberAsString, ParseNumberError & error)
{
	int intNumber = MIN_VALUE;
	Number number = MIN_VALUE;
	error = ParseNumberError::NoError;

	try
	{
		intNumber = stoi(numberAsString);
		if ((intNumber < MIN_VALUE) || (intNumber > MAX_VALUE))
		{
			error = ParseNumberError::OutOfRange;
		}
		else
		{
			number = static_cast<Number>(intNumber);
		}
	}
	catch (const invalid_argument & e)
	{
		error = ParseNumberError::NotANumber;
	}
	catch (const out_of_range & e)
	{
		error = ParseNumberError::OutOfRange;
	}

	return number;
}

string GetParseNumberErrorAsString(const ParseNumberError & error)
{
	string errorString;
	switch (error)
	{
		case ParseNumberError::NoError:
			errorString = "";
			break;
		case ParseNumberError::NotANumber:
			errorString = "Error: argument must be a number";
			break;
		case ParseNumberError::OutOfRange:
			errorString = "Error: number must be in range <" + to_string(MIN_VALUE) + ", " + to_string(MAX_VALUE) + ">";
			break;
		default:
			errorString = "Error: unknown error";
			break;
	}
	return errorString;
}

Number FlipNumber(const Number & number)
{
	Number flippedNumber = 0;
	for (auto i = 0; i < BIT_NUMBER; i++)
	{
		flippedNumber <<= 1;
		flippedNumber |= ((number >> i) & 0x01);
	}
	return flippedNumber;
}