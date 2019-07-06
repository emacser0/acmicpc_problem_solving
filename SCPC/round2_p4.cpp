#include <iostream>
#include <vector>
#include <iostream>
using namespace std;
int M, N;
typedef struct
{
  int i;
  int j;
} Point;
std::vector<Point> v;
int visited[25004];
Point offset_list[9] = {{0, 0}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}};
char map[54][504];
int Max(int a, int b)
{
  return a > b ? a : b;
}
int Min(int a, int b)
{
  return a < b? a : b;
}
int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case < T; test_case++)
	{
    cin >> N >> M;
    v.clear();
    fill(visited, visited + 25000, 0);
    for(int i = 0; i < N; ++i)
    {
      cin >> map[i];
      for(int j = 0; j < M; ++j)
      {
        if(map[i][j] == '1')
        {
          v.push_back({i, j});
        }
      }
    }

    int len = v.size(), boom_cnt = 0;
    vector<Point> boom_v;
    for(int i = 0; i < len; ++i)
    {
      if(visited[i] == 1) continue;
      visited[i] = 1;
      int max = 1, maxj = 0;
      for(int j = 0; j < 9; ++j)
      {
        int cnt = 1;
        int y = v[i].i + offset_list[j].i;
        int x = v[i].j + offset_list[j].j;
        for(int k = 0; k < len; ++k)
        {
          if(k == i) continue;
          if(visited[k] == 0 && v[k].i >= y - 1 && v[k].i <= y + 1 && v[k].j >= x - 1 && v[k].j <= x + 1)
          {
            cnt += 1;
          }
        }
        if(cnt > max)
        {
          max = cnt;
          maxj = j;
        }
      }

      if(max == 1)
      {
        visited[i] == 1;
        boom_cnt += 1;
        boom_v.push_back(v[i]);
        continue;
      }
      int y = v[i].i + offset_list[maxj].i;
      int x = v[i].j + offset_list[maxj].j;
      for(int j = 0; j < len; ++j)
      {
        if(j == i) continue;
        if(visited[j] == 0 && v[j].i >= y - 1 && v[j].i <= y + 1 && v[j].j >= x - 1 && v[j].j <= x + 1)
        {
          visited[j] = 1;
        }
      }
      boom_cnt += 1;
      boom_v.push_back({y, x});
    }
		cout << "Case #" << test_case+1 << endl;
    cout << boom_cnt << endl;
    for(auto &i : boom_v)
    {
      cout << i.i << " " << i.j << endl;
    }
	}
	return 0;
}
