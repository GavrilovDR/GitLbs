int MatrixOperations::sumUpperLeftTriangle()
{
	int sum = 0;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			sum += matrix[i][j];
		}
	}
	return sum;
}

int MatrixOperations::sumUpperRightTriangle()
{
	int sum = 0;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			sum += matrix[i][j];
		}
	}
	return sum;
}

int MatrixOperations::minElementInUpperLeftTriangle()
{
	int minElement = matrix[0][0];
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			if (matrix[i][j] < minElement)
			{
				minElement = matrix[i][j];
			}
		}
	}
	return minElement;
}

int MatrixOperations::maxElementInUpperLeftTriangle()
{
	int maxElement = matrix[0][0];
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			if (matrix[i][j] > maxElement)
			{
				maxElement = matrix[i][j];
			}
		}
	}
	return maxElement;
}

int MatrixOperations::minElementInUpperRightTriangle()
{
	int minElement = matrix[0][1];
	for (int i = 0; i < 4; ++i)
		{
			for (int j = i; j < 4; ++j)
			{
				if (matrix[i][j] < minElement)
				{
					minElement = matrix[i][j];
				}
			}
		}
		return minElement;
}

int MatrixOperations::maxElementInUpperRightTriangle()
{
	int maxElement = matrix[0][1];
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (matrix[i][j] > maxElement)
			{
				maxElement = matrix[i][j];
			}
		}
	}
	return maxElement;
}

extern "C" {
	int calculateSumUpperLeftTriangle(const std::vector<std::vector<int>>& matrix) {
	MatrixOperations matrixOps(matrix);
	return matrixOps.sumUpperLeftTriangle();
	}
	int calculateSumUpperRightTriangle(const std::vector<std::vector<int>>& matrix) {
	MatrixOperations matrixOps(matrix);
	return matrixOps.sumUpperRightTriangle();
	}
	int calculateMinElementInUpperLeftTriangle(const std::vector<std::vector<int>>& matrix) {
	MatrixOperations matrixOps(matrix);
	return matrixOps.MinElementInUpperLeftTriangle();
	}
	int calculateMaxElementInUpperLeftTriangle(const std::vector<std::vector<int>>& matrix) {
	MatrixOperations matrixOps(matrix);
	return matrixOps.MaxElementInUpperLeftTriangle();
	}
	int calculateMinElementInUpperRightTriangle(const std::vector<std::vector<int>>& matrix) {
	MatrixOperations matrixOps(matrix);
	return matrixOps.MinElementInUpperRightTriangle();
	}
	int calculateMaxElementInUpperRightTriangle(const std::vector<std::vector<int>>& matrix) {
	MatrixOperations matrixOps(matrix);
	return matrixOps.MaxElementInUpperRightTriangle();
	}