#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <deque>

#define MAX_COUNT 99999

std::vector<int> graph[MAX_COUNT];
bool hasAllergy[MAX_COUNT];
bool visited[MAX_COUNT];

// dfs로 풀면 stack overflow가 나기 때문에 bfs로 풀어야 함.
void dfsCount(int current)
{
	visited[current] = true;
	hasAllergy[current] = true;

	for (int next : graph[current])
	{
		if (!visited[next])
		{
			dfsCount(next);
		}
	}
}


// std::deque를 사용한 bfs 구현
void bfsCount(int start)
{
	std::deque<int> dq;
	dq.push_back(start);

	while (dq.size())
	{
		int current = dq.front();
		dq.pop_front();

		visited[current] = true;
		hasAllergy[current] = true;

		for (int next : graph[current])
		{
			if (visited[next])
			{
				continue;
			}

			dq.push_back(next);
		}
	}
}

int main()
{
	int N;

	// 60000개가 넘는 줄을 stdin으로 받으면 너무 느림.
	std::ifstream stream("4.txt", std::ios_base::in);

	std::cout << "loading..." << std::endl;

	stream >> N;
	stream.ignore();

	char buf[1024];
	while (!stream.eof())
	{
		stream.getline(buf, sizeof(buf));

		std::stringstream dataStream(buf);

		int index;
		dataStream >> index;

		int temp;
		while (dataStream >> temp)
		{
			graph[index].push_back(temp);
		}
	}

	std::cout << "Data loaded successfully!" << std::endl;

	bfsCount(1);

	int allergyCount = 0;
	for (int i = 1; i <= N; ++i)
	{
		allergyCount += hasAllergy[i];
	}

	std::cout << "Required vaccine count: " << N - allergyCount << std::endl;

	return 0;
}