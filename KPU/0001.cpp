#include <iostream>
#include <vector>
#include <string>
bool is_prime(int n)
{
	for (int i = 2; i * i <= n; ++i)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}

bool is_palindrome(int n)
{
	std::vector<int> arr;
	while (n)
	{
		arr.push_back(n % 10);
		n /= 10;
	}

	int size = arr.size();
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] != arr[size - i - 1])
		{
			return false;
		}
	}

	return true;
}
int main()
{
	int n;
	std::cin >> n;

	while (1)
	{
		if (is_prime(n) && is_palindrome(n))
		{
			std::cout << n << std::endl;
			break;
		}
		++n;
	}
}