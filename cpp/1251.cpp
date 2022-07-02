#include <iostream>
#include <string>
#include <algorithm>

int main()
{
	std::string str;
	std::cin >> str;

	std::string result = "";

	for (int i = 1; i < str.size() - 1; ++i)
	{
		for (int j = i + 1; j < str.size(); ++j)
		{
			std::string left = str.substr(0, i);
			std::string mid = str.substr(i, j - i);
			std::string right = str.substr(j, str.size() - j);

			std::reverse(left.begin(), left.end());
			std::reverse(mid.begin(), mid.end());
			std::reverse(right.begin(), right.end());

			std::string current = left + mid + right;

			if (result == "")
			{
				result = current;
			}
			else if(result > current)
			{
				result = current;
			}
		}
	}

	std::cout << result << std::endl;
}