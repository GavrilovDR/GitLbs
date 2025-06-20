#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <Windows.h>
#include "mtrxops.h"
using namespace std;

void showHelp()
{
	cout << "Using:\n"
		<< "--help 	View this message\n"
		<< "--input <file.txt> input file contain matrix\n"
		<< "--part <part> Part of maxrix (upper_left or upper_right)\n"
		<< "--operation <operation> Operation (sum, min, max)\n";
		<< "ВНЕСЕНО ИЗМЕНЕНИЕ В КОД СОГЛАСНО УСЛОВИЮ ЗАДАЧИ";
}

int main(int argc, char* argv[])
{
	if (argc != 1)
	{
		showHelp();
		return 1;
	}
	
	string inputFile, part, operation;
	
	for (int i = 1; i < argc; i += 2)
	{
		string arg = argv[i];
		if (arg == "--help")
		{
			showHelp();
			return 0;
		} else if (arg == "--input")
		{
			inputFile = argv[i + 1];
		} else if (arg == "--part")
		{
			part = argv[i + 1];
		} else if (arg == "--operation")
		{
			operation = argv[i + 1];
		}
	}
	
	vector<vector<int>> matrix(4, vector<int>(4));
	ifstream file(inputFile);
	if (!file.is_open())
	{
		cout << "OPEN FILE ERROR\n";
		return 1;
	}
	
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			file >> matrix[i][j];
		}
	}
	file.close();
	
	MatrixOperations matrixOps(matrix);
	
	int result = 0;
	
	if (part == "upper_left")
	{
		if (operation == "sum")
		{
			result = matrixOps.sumUpperLeftTriangle();
		}else if (operation == "min")
		{
			result = matrixOps.minElementInUpperLeftTriangle();
		} else if (operation == "max")
		{
			result = matrixOps.maxElementInUpperLeftTriangle();
		}
	} else if (part == "upper_right")
	{
		if (operation == "sum")
		{
			result = matrixOps.sumUpperRightTriangle();
		}else if (operation == "min")
		{
			result = matrixOps.minElementInUpperRightTriangle();
		} else if (operation == "max")
		{
			result = matrixOps.maxElementInUpperRightTriangle();
		}
	} else 
	{
		cout << "What?" << endl;
		return 1;
	}
	cout << "Result: " << result << endl;
	return 0;
}
