#include <iostream>
#include <vector>

bool isPrime[1000004];

int main()
{
	int N;
	std::cin >> N;
	std::fill(isPrime, isPrime + N + 1, true);

	for (int i = 2; i <= N; ++i)
	{
		if (isPrime[i])
		{
			for (int j = i * 2; j <= N; j += i)
			{
				isPrime[j] = false;
			}
		}
	}

	int RN = N;
	if (RN % 2)
	{
		RN -= 5;
	}
	else
	{
		RN -= 4;
	}
	
	int a = 0;
	int b = 0;
	for (int i = 2; i <= RN; ++i)
	{
		if (isPrime[i] && isPrime[RN - i])
		{
			a = i;
			b = RN - i;
			break;
		}
	}


	if (RN < 4)
	{
		std::cout << -1 << std::endl;
	}
	else if (N % 2)
	{
		std::cout << 2 << " " << 3 << " " << a << " " << b << std::endl;
	}
	else
	{
		std::cout << 2 << " " << 2 << " " << a << " " << b << std::endl;
	}
}