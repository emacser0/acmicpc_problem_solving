#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <array>
#include <set>
#include <unordered_map>
#include <tuple>
#include <algorithm>
#include <functional>

// Aliases

using ll = long long;
using ull = unsigned long long;

using IntPair = std::pair<int, int>;
using StringPair = std::pair<std::string, std::string>;
using LLPair = std::pair<long long, long long>;
using ULLPair = std::pair<unsigned long long, unsigned long long>;

using IntStringPair = std::pair<int, std::string>;
using StringIntPair = std::pair<std::string, int>;

using IntStringUnorderedMap = std::unordered_map<int, std::string>;
using StringIntUnorderedMap = std::unordered_map<std::string, int>;

using MaxHeap = std::priority_queue<int, std::vector<int>, std::less<int>>; // 최대 힙이 greater가 아니라 less 임에 주의할 것.
using MinHeap = std::priority_queue<int, std::vector<int>, std::greater<int>>; // 마찬가지.

#define PI 3.1415926535897932384626433832795

// Print

#define Print(A, ...) \
std::cout << A << std::endl; \

#define Print2(A, B) \
std::cout << A << " " << B << std::endl; \

#define Print3(A, B, C) \
std::cout << A << " " << B << " " << C << std::endl; \

#define Print4(A, B, C, D) \
std::cout << A << " " << B << " " << C << " " << D << std::endl; \

#define Print5(A, B, C, D, E) \
std::cout << A << " " << B << " " << C << " " << D << " " << E << std::endl; \

#define Print6(A, B, C, D, E, F) \
std::cout << A << " " << B << " " << C << " " << D << " " << E << " " << F << std::endl; \

#define Print7(A, B, C, D, E, F, G) \
std::cout << A << " " << B << " " << C << " " << D << " " << E << " " << F << G << std::endl; \

#define PrintArray(Arr, Length) \
for(int i = 0; i < Length; ++i) \
{ \
	std::cout << Arr[i]; \
	if (i < Length - 1) \
	{ \
		std::cout << " "; \
    } \
} \
std::cout << std::endl; \

#define PrintArrayNewLine(Arr, Length) \
for(int i = 0; i < Length; ++i) \
{ \
	std::cout << Arr[i] << std::endl; \
} \


#define PrintArray2D(Arr, Height, Width) \
for(int i = 0; i < Height; ++i) \
{ \
	for (int j = 0; j < Width; ++j) \
	{ \
		std::cout << Arr[i][j]; \
		if (j < Width - 1) \
		{ \
			std::cout << " "; \
		} \
	} \
	std::cout << std::endl; \
} \

#define PrintArrayWithoutSpace(Arr, Height, Width) \
for(int i = 0; i < Height; ++i) \
{ \
	for (int j = 0; j < Width; ++j) \
	{ \
		std::cout << Arr[i][j]; \
	} \
	std::cout << std::endl; \
} \

// Min, Max, Argmin, Argmax

template <typename T>
T Min(T a, T b)
{
	return a < b ? a : b;
}

template <typename T>
T Max(T a, T b)
{
	return a > b ? a : b;
}

template <typename T>
int Argmin(const std::vector<T>& v)
{
	if (v.empty())
	{
		return -1;
	}

	int argmin = 0;
	int min = v[0];
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i] < min)
		{
			min = v[i];
			argmin = i;
		}
	}

	return argmin;
}

template <typename T>
int Argmax(const std::vector<T>& v)
{
	if (v.empty())
	{
		return -1;
	}

	int argmax = 0;
	int max = v[0];
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i] > max)
		{
			max = v[i];
			argmax = i;
		}
	}

	return argmax;
}

// Trie

int rmCount = 0;

#define ALPHABETS 150

int CharToIndex(char c) {
	return c;
}

int T;
int N1, N2;

std::vector<std::string> toRemove;
std::vector<std::string> notToRemove;

struct Trie {

	bool isTerminal; // this represents end of string
	Trie* children[ALPHABETS];

	// Constructor
	Trie() : isTerminal(false) {
		for (int i = 32; i < ALPHABETS; ++i)
		{
			children[i] = NULL;
		}
	}

	// Delete all this->children
	~Trie() {
		for (int i = 32; i < ALPHABETS; ++i) {
			if (this->children[i])
			{
			}
		}
	}

	void Insert(const char* key) {
		if (*key == '\0') {
			this->isTerminal = true;
		}
		else {
			int index = CharToIndex(*key);

			if (this->children[index] == NULL)
			{
				this->children[index] = new Trie();
			}
			this->children[index]->Insert(key + 1);
		}
	}

	Trie* Find(const char* key) {
		if (*key == 0) {
			return this;
		}

		int index = CharToIndex(*key);
		if (this->children[index] == 0) {
			return NULL;
		}

		auto subTree = this->children[index]->Find(key + 1);

		return subTree;
	}

	bool StringExists(const char* key) {
		if (*key == 0 && isTerminal) {
			return true;
		}

		int index = CharToIndex(*key);
		if (this->children[index] == 0) {
			return false;
		}
		return this->children[index]->StringExists(key + 1);
	}

	void Delete(int index, std::string& prev)
	{
		bool removed = false;
		for (int i = 32; i < ALPHABETS; ++i)
		{
			bool impossible = false;
			if (this->children[i] == NULL)
			{
				continue;
			}
			
			std::string s = prev;
			char c[1] = { i };
			s.append(c);

			for (auto& str : notToRemove)
			{
				if (str.substr(0, index + 1) != s)
				{
					continue;
				}

				if (this->children[i]->StringExists(str.substr(index, str.size() - index - 1).c_str()))
				{
					impossible = true;
				}
			}

			if (impossible)
			{
				continue;
			}

			this->children[i] = NULL;
			removed = true;
		}

		if (removed)
		{
			++rmCount;
		}

		for (int i = 32; i < ALPHABETS; ++i)
		{
			if (this->children[i] != NULL)
			{
				std::string s = prev;
				char c[1] = { i };
				s.append(c);
				this->children[i]->Delete(index + 1, s);
			}
		}
	}
};

int main()
{
	std::cin >> T;

	while (T--)
	{
		std::cin >> N1;

		Trie* trie = new Trie();

		toRemove.clear();
		notToRemove.clear();

		for (int i = 0; i < N1; ++i)
		{
			std::string t;
			std::cin >> t;

			trie->Insert(t.c_str());
			toRemove.push_back(t);
		}

		std::cin >> N2;

		for (int i = 0; i < N2; ++i)
		{
			std::string t;
			std::cin >> t;

			trie->Insert(t.c_str());
			notToRemove.push_back(t);
		}

		if (notToRemove.size() == 0)
		{
			std::cout << 1 << std::endl;
			continue;
		}

		std::string prev = "";

		trie->Delete(0, prev);

		std::cout << rmCount << std::endl;

		for (int i = 0; i < toRemove.size(); ++i)
		{
			std::cout << trie->StringExists(toRemove[i].c_str()) << std::endl;
		}

		for (int i = 0; i < notToRemove.size(); ++i)
		{
			std::cout << trie->StringExists(notToRemove[i].c_str()) << std::endl;
		}
	}
}