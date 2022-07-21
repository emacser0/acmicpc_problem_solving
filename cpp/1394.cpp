#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>

long long pows[1000001];

int main()
{
	std::string list;
	std::cin >> list;

	std::unordered_map<char, int> indices;
	for (int i = 0; i < list.size(); ++i)
	{
		indices[list[i]] = i;
	}

	std::string password;
	std::cin >> password;
	
	long long count = 1;
	long long pow = 1;
	for (int i = 1; i < password.size(); ++i)
	{
		pow = (pow * list.size()) % 900528;
		count = (count + pow) % 900528;
	}

	pows[0] = 1;
	for (int i = 1; i < password.size(); ++i)
	{
		pows[i] = (pows[i - 1] * list.size()) % 900528;
	}

	for (int i = 0; i < password.size(); ++i)
	{	
		count = (count % 900528 + indices[password[i]] * pows[password.size() - i - 1] % 900528) % 900528;
	}

	std::cout << count << std::endl;
}