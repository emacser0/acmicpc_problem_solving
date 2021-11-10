#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <functional>
#include <set>
#include <cstdio>

int matrix[99][99];

int mainB()
{
	int A, B;
	std::cin >> A >> B;

	for (int i = 0; i < A; ++i)
	{
		for (int j = 0; j < B; ++j)
		{
			matrix[i][j] = i * B + j + 1;
		}
	}

	std::cout << "M" << std::endl;
	for (int i = 0; i < A; ++i)
	{
		for (int j = 0; j < B; ++j)
		{
			std::cout << matrix[i][j];
			if (j < B - 1)
			{
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
	std::cout << "R" << std::endl;
	for (int i = 0; i < B; ++i)
	{
		for (int j = A - 1; j >= 0; --j)
		{
			std::cout << matrix[j][i];
			if (j > 0)
			{
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
	std::cout << "L" << std::endl;
	for (int i = B - 1; i >= 0; --i)
	{
		for (int j = 0; j < A; ++j)
		{
			std::cout << matrix[j][i];
			if (j < A - 1)
			{
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
	std::cout << "T" << std::endl;
	for (int i = 0; i < B; ++i)
	{
		for (int j = 0; j < A; ++j)
		{
			std::cout << matrix[j][i];
			if (j < A - 1)
			{
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}

	return 0;
}