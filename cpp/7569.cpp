#include <iostream>
#include <vector>
#include <deque>
#include <array>
int M, N, H, unable, empty;
char storage[104][104][104], visited[104][104][104];
int cnt = 0, d[6][3] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
std::deque<std::array<int,3>> q;
int main()
{
  scanf("%d%d%d", &M, &N, &H);
  for(int i = 0; i < H; ++i)
  {
    for(int j = 0; j < N; ++j)
    {
      for(int k = 0; k < M; ++k)
      {
        scanf("%d",&storage[i][j][k]);
        if(storage[i][j][k] == 1) q.push_back({i, j, k});
        if(storage[i][j][k] == -1) empty += 1;
      }
    }
  }
  cnt += q.size();
  int day = 0;
  while(cnt < M * N * H - empty && !unable)
  {
    day += 1;
    int size = q.size(), prevcnt = cnt;
    while(size--)
    {
      std::array<int, 3> cur = q.front();
      q.pop_front();
      visited[cur[0]][cur[1]][cur[2]] = 1;
      for(int i = 0; i < 6; ++i)
      {
        int nz = cur[0] + d[i][0], ny = cur[1] + d[i][1], nx = cur[2] + d[i][2];
        if(nz >= 0 && nz < H && ny >= 0 && ny < N && nx >= 0 && nx < M && storage[nz][ny][nx] == 0 && visited[nz][ny][nx] == 0)
        {
          storage[nz][ny][nx] = 1;
          visited[nz][ny][nx] = 1;
          q.push_back({nz, ny, nx});
          cnt += 1;
        }
      }
    }
    if(cnt == prevcnt) unable = 1;
  }
  printf("%d\n", unable ? -1 : day);
}
