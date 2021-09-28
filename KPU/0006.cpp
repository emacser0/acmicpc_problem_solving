#include <iostream>
#include <string>

int board[99999];

int main()
{
	int N, M;
	std::cin >> N >> M;

	int position = 1;
	int score = 1;

	for (auto i = 1; i < N + 1; ++i)
	{
		char ch;
		std::cin >> ch;
		board[i] = ch == '+' ? 1 : 0;
	}

	for (auto i = 0; i < M; ++i)
	{
		int t;
		std::cin >> t;

		if (board[position] && position + t <= N)
		{
			position += t;
		}
		else if(!board[position] && position - t >= 1)
		{
			position -= t;
		}

		score += position == 1;
	}

	std::cout << score << std::endl;
}