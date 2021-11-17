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

// GCD, LCM

long long GCD(long long a, long long b)
{
	long long r = 0;
	while (true)
	{
		r = a % b;

		if (r == 0)
		{
			return b;
		}

		a = b;
		b = r;
	}
}

long long LCM(long long a, long long b)
{
	return a * b / GCD(a, b);
}

// Prime

template <typename T>
bool IsPrime(T n)
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

template <typename T>
void GetPrimeArray(T* arr, T n)
{
	for (int i = 2; i <= n; ++i)
	{
		arr[i] = 1;
	}

	for (int i = 2; i <= sqrt(n); ++i)
	{
		if (arr[i] == 0)
		{
			continue;
		}

		for (int j = i * i; j <= n; j += i)
		{
			arr[j] = 0;
		}
	}
}

// Trie

#define ALPHABETS 26

int CharToIndex(char c) {
	return toupper(c) - 'A';
}

struct Trie {

	bool isTerminal; // this represents end of string
	Trie* children[ALPHABETS];

	// Constructor
	Trie() : isTerminal(false) {
		for (int i = 0; i < ALPHABETS; ++i)
		{
			children[i] = NULL;
		}
	}

	// Delete all this->children
	~Trie() {
		for (int i = 0; i < ALPHABETS; ++i) {
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

			std::cout << index << std::endl;

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

		return this->children[index]->Find(key + 1);
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
};

template<int N>
class DisjointSet
{
public:
	DisjointSet()
	{
		for (int i = 0; i < N; i++)
			parent[i] = i;
	}

	int find(int u)
	{
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}

	void merge(int u, int v)
	{
		u = find(u);
		v = find(v);

		if (u == v) return;

		parent[u] = v;

		find(v);
	}

private:
	int parent[N + 1];
};

// Graph

void FloydWarshal(std::vector<std::vector<int>>& graph)
{
	for (int k = 0; k < graph.size(); k++)  // k 는 거쳐가는 정점
	{
		for (int i = 0; i < graph.size(); i++)  // i는 출발 정점
		{
			for (int j = 0; j < graph.size(); j++)  // j는 도착 정점
			{
				if (graph[i][k] + graph[k][j] < graph[i][j])  // 점화식 distance[i,j] = min(distance[i,j], distance[i,n] + distance[n,j])
					graph[i][j] = graph[i][k] + graph[k][j];
			}
		}
	}
}

void Dijkstra(int start, std::vector<std::vector<IntPair>>& graph, std::vector<int>& distance)
{
	std::priority_queue<IntPair, std::vector<IntPair>, std::greater<IntPair>> pq; // 거리, 노드 인덱스

	pq.push({ 0, start }); //시작 노드로 가기위한 최단 경로는 0으로 설정하여, 큐에 삽입.
	distance[start] = 0;

	while (!pq.empty()) {
		int curr = pq.top().second;
		int currCost = pq.top().first;
		pq.pop();

		//지금 꺼낸 것보다 더 짧은 경로를 알고 있다면
		//지금 꺼낸 것을 무시한다.
		if (distance[curr] < currCost) continue;

		//인접한 정점들을 모두 검사
		for (auto& p : graph[curr])
		{
			int next = p.first;
			int nextDist = p.second + currCost;

			if (distance[next] > nextDist)   //최단 경로를 찾았다면?
			{
				distance[next] = nextDist; //dist 배열 갱신
				pq.push({ distance[next], next });
			}
		}
	}
}

int cnt[5];
char map[20][20];

int visited[20][20];

int shapes[11][4][4] =
{
	{{ 1, 1, 0, 0},{ 1, 1, 0, 0 },{ 0, 0, 0, 0 },{ 0, 0, 0, 0 }},
	{{1, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
	{{1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}},
	{{0, 1, 1, 0}, {1, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
	{{1, 0, 0, 0}, {1, 1, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}},
	{{1, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
	{{0, 1, 0, 0}, {1, 1, 0, 0}, {1, 0, 0, 0}, {0, 0, 0, 0}},
	{{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
	{{1, 0, 0, 0}, {1, 1, 0, 0}, {1, 0, 0, 0}, {0, 0, 0, 0}},
	{{1, 1, 1, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
	{{0, 1, 0, 0}, {1, 1, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}}
};

int shapeIndices[11]
{
	0, 1, 1, 2, 2, 3, 3, 4, 4, 4, 4
};

using shape = std::array<std::array<int, 4>, 4>;

std::vector<int> sIndices;

bool check(char ch, int index, int y, int x)
{
	if (ch < 'a' || ch > 'z')
	{
		return false;
	}

	int cnt = 0;
	for (int i = 0; i < 4; ++i)
	{
		for(int j = 0; j < 4; ++j)
		{
			if (map[y + i][x + j] == ch && shapes[index][i][j])
			{
				cnt += 1;
			}
		}
	}

	if (cnt == 4)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	int N, M;

	std::cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		std::string s;
		std::cin >> s;
		for (int j = 0; j < M; ++j)
		{
			map[i][j] = s[j];
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			for (int k = 0; k < 11; ++k)
			{
				bool result = check(map[i][j], k, i, j) || check(map[i + 1][j], k, i, j);

				if (result)
				{
					cnt[shapeIndices[k]]++;
				}
			}
		}
	}

	PrintArrayNewLine(cnt, 5);
}