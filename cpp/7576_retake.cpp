#include <iostream>
#include <vector>
#include <deque>
#include <array>
int M, N, unable, empty;
char storage[1004][1004], visited[1004][1004];
int cnt = 0, d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
std::deque<std::array<int,2>> q;
int main()
{
  scanf("%d%d", &M, &N);
  for(int i = 0; i < N; ++i)
  {
    for(int j = 0; j < M; ++j)
    {
      scanf("%d",&storage[i][j]);
      if(storage[i][j] == 1)
        q.push_back({i, j});
      if(storage[i][j] == -1)
        empty += 1;
    }
  }
  cnt += q.size();
  int day = 0;
  while(cnt < M * N - empty && !unable)
  {
    day += 1;
    int size = q.size(), prevcnt = cnt;
    while(size--)
    {
      std::array<int, 2> cur = q.front();
      q.pop_front();
      visited[cur[0]][cur[1]] = 1;
      for(int i = 0; i < 4; ++i)
      {
        int ny = cur[0] + d[i][0], nx = cur[1] + d[i][1];
        if(ny >= 0 && ny < N && nx >= 0 && nx < M && storage[ny][nx] == 0 && visited[ny][nx] == 0)
        {
          storage[ny][nx] = 1;
          visited[ny][nx] = 1;
          q.push_back({ny, nx});
          cnt += 1;
        }
      }
    }
    if(cnt == prevcnt) unable = 1;
  }
  printf("%d\n", unable ? -1 : day);
}
