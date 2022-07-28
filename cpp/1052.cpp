#include <iostream>

int main()
{
	int N, K;
	std::cin >> N >> K;

	
	int r = 0;
	for(;;++r,++N)
	{
		int n = N;
		int cnt = 0;
		while (n)
		{
			if (n % 2)
			{
				++cnt;
			}
			n /= 2;
		}

		if (cnt <= K)
		{
			break;
		}
	}

	std::cout << r << std::endl;
}