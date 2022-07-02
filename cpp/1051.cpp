#include <iostream>
#include <string>

int rect[54][54];

int min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	int N, M;
	std::cin >> N >> M;
	std::cin.ignore();

	std::string str;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> str;
		for (int j = 0; j < str.size(); ++j)
		{
			rect[i][j] = str[j] - '0';
		}
	}

	int squareSize = 1;

	for (int i = 0; i < min(N, M); ++i)
	{
		for (int j = 0; j < N - i; ++j)
		{
			for (int k = 0; k < M - i; ++k)
			{
				if (rect[j][k] == rect[j + i][k] && rect[j + i][k] == rect[j][k + i] && rect[j][k + i] == rect[j + i][k + i])
				{
					squareSize = (i + 1) * (i + 1);
				}
			}
		}
	}

	std::cout << squareSize << std::endl;
}