#include <iostream>
#include <string>
#include <vector>
#include <functional>

char minsik[26] = { 'a', 'b', 'k', 'd', 'e', 'g', 'h', 'i', 'l', 'm', 'n', '!', 'o', 'p', 'r', 's', 't', 'u', 'w', 'y' };
int order[255];

bool compare(const std::string& a, const std::string& b)
{
	int i = 0;
	int al = a.size();
    int bl = b.size();
	while (i < al && i < bl)
	{
		if (order[a[i]] != order[b[i]])
		{
			return order[a[i]] > order[b[i]];
		}
		++i;
	}

	return al > bl;
}

void sort(std::vector<std::string>& arr, std::function<bool(const std::string&, const std::string&)> compare, int left, int right)
{
	if (left >= right)
	{
		return;
	}

	int pivot = left;
	int i = left;
	int j = right;

	while (i < j)
	{		
		while (compare(arr[j], arr[pivot]))
		{
			--j;
		}
		while (i < j && !compare(arr[i], arr[pivot]))
		{
			++i;
		}

		std::string temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}

	std::string temp = arr[pivot];
	arr[pivot] = arr[i];
	arr[i] = temp;

	sort(arr, compare, left, i);
	sort(arr, compare, i + 1, right);
}

int main()
{
	int n;
	std::cin >> n;

	std::vector<std::string> words;

	for (int i = 0; i < 26; ++i)
	{
		order[minsik[i]] = i + 1;
	}

	for (int i = 0; i < n; ++i)
	{
		std::string word;
		std::cin >> word;

		std::string::size_type offset = 0;
		std::string::size_type pos = std::string::npos;
		while ((pos = word.find("ng", offset)) != std::string::npos)
		{
			word.replace(word.begin() + pos, word.begin() + pos + 2, "!");
			offset = pos + 1;
		}
		words.push_back(word);
	}

	sort(words, compare, 0, n - 1);

	for (const auto& word : words)
	{
		for (auto ch : word)
		{
			if (ch == '!')
			{
				std::cout << "ng";
			}
			else
			{
				std::cout << ch;
			}
		}
		std::cout << std::endl;
	}
}