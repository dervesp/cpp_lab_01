#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		cout << "Correct usage: <input file1> [<input file2> ... <input fileN>] <output file>" << endl;
		return 1;
	}

	string outputFileName = argv[argc - 1];
	ofstream outputFile(outputFileName, ios_base::binary | ios_base::out);
	if (!outputFile.is_open())
	{
		cout << "Error while opening output file: " << outputFileName << endl;
		return 1;
	}
	else
	{
		cout << "Output file: " << outputFileName << endl;

		int inputFileCount = argc - 2;
		for (int i = 0; i < inputFileCount; i++)
		{
			string inputFileName = argv[i + 1];
			ifstream inputFile(inputFileName, ios_base::binary | ios_base::in);
			if (!inputFile.is_open())
			{
				cout << "Error while opening input file: " << inputFileName << endl;
				return 1;
			}
			else
			{
				cout << "Input file" << (i + 1) << ": " << inputFileName << endl;
				char ch;
				while (inputFile.get(ch))
				{
					if (!outputFile.put(ch))
					{
						cout << "Error while writing to output file: " << outputFileName << endl;
						return 1;
					}
				}
				inputFile.close();
			}
		}
		if (!outputFile.flush())
		{
			cout << "Error while saving output file: " << outputFileName << endl;
			return 1;
		}
		outputFile.close();
	}
    return 0;
}