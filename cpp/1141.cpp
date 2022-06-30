#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <cstring>

struct AlphabetCount
{
	AlphabetCount(const std::string& str)
	{
		memset(alphabetCnt, 0, sizeof(alphabetCnt));

		front = str.front();
		back = str.back();

		for (auto ch : str)
		{
			++alphabetCnt[ch];
		}

		cases.insert(str);
	}

	bool contains(const std::string& str)
	{
		if (str.front() != front || str.back() != back)
		{
			return false;
		}

		int cnt[256];
		memset(cnt, 0, sizeof(cnt));

		for (auto ch : str)
		{
			++cnt[ch];
		}

		return memcmp(alphabetCnt, cnt, sizeof(cnt)) == 0;
	}

	int alphabetCnt[256];
	char front;
	char back;

	std::set<std::string> cases;
};

int main()
{
	int N;
	std::cin >> N;

	std::vector<AlphabetCount> words;

	for (int i = 0; i < N; ++i)
	{
		std::string str;
		std::cin >> str;

		bool isSubset = false;
		for (auto& acnt : words)
		{
			if (acnt.contains(str))
			{
				acnt.cases.insert(str);
				isSubset = true;
				break;
			}
		}

		if (!isSubset)
		{
			words.push_back(AlphabetCount(str));
		}
	}

	int M;
	std::cin >> M;
	std::cin.ignore();

	for (int i = 0; i < M; ++i)
	{
		std::string line;

		std::getline(std::cin, line);
		std::stringstream ss(line);

		std::string word;

		int cases = 1;		
		while (ss >> word)
		{
			bool isSubset = false;

			for (auto& acnt : words)
			{
				if (acnt.contains(word))
				{
					cases *= acnt.cases.size();
					isSubset = true;
					break;
				}
			}		

			if (!isSubset)
			{
				cases = 0;
			}
		}

		std::cout << cases << std::endl;
	}
}