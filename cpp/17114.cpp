#include <iostream>
#include <vector>
#include <deque>
#include <array>
int M, N, O, P, Q, R, S, T, U, V, W, unable, empty;
char storage[9][9][9][3][3][3][3][3][3][3][3];
int cnt = 0, d[22][11] =
{
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1}
};
std::deque<std::array<int,11>> q;
int main()
{
  scanf("%d%d%d%d%d%d%d%d%d%d%d", &M, &N, &O, &P, &Q, &R, &S, &T, &U, &V, &W);
  for(int w = 0; w < W; ++w)
    for(int v = 0; v < V; ++v)
      for(int u = 0; u < U; ++u)
        for(int t = 0; t < T; ++t)
          for(int s = 0; s < S; ++s)
            for(int r = 0; r < R; ++r)
              for(int q = 0; q < Q; ++q)
                for(int p = 0; p < P; ++p)
                  for(int o = 0; o < O; ++o)
                    for(int n = 0; n < N; ++n)
                      for(int m = 0; m < M; ++m)
                      {
                        scanf("%d",&storage[m][n][o][p][q][r][s][t][u][v][w]);
                        if(storage[m][n][o][p][q][r][s][t][u][v][w] == 1)
                        {
                          int arr[11] = {m,n,o,p,q,r,s,t,u,v,w};
                          q.push_back(arr);
                        }
                        if(storage[m][n][o][p][q][r][s][t][u][v][w] == -1) empty += 1;
                      }
  cnt += q.size();
  int day = 0;
  long long max = M * N * O * P * Q * R * S * T * U * V * W;
  while(cnt < max - empty && !unable)
  {
    day += 1;
    int size = q.size(), prevcnt = cnt;
    while(size--)
    {
      std::array<int, 11> cur = q.front();
      q.pop_front();
      for(int i = 0; i < 22; ++i)
      {
        int nw = cur[0] + d[i][0],
            nv = cur[1] + d[i][1],
            nu = cur[2] + d[i][2],
            nt = cur[3] + d[i][3],
            ns = cur[4] + d[i][4],
            nr = cur[5] + d[i][5],
            nq = cur[6] + d[i][6],
            np = cur[7] + d[i][7],
            no = cur[8] + d[i][8],
            nn = cur[9] + d[i][9],
            nm = cur[10] + d[i][10];
        if(nw >= 0 && nv >= 0 && nu >= 0 && nt >= 0 && ns >= 0 && nr >= 0 && nq >= 0 && np >= 0 && no >= 0 && nn >= 0 && nm >= 0 &&
           nw < W && nv < V && nu < U && nt < T && ns < S && nr < R && nq < Q && np < P && no < O && nn < N && nm < M &&
           storage[nm][nn][no][np][nq][nr][ns][nt][nu][nv][nw] == 0)
        {
          storage[nm][nn][no][np][nq][nr][ns][nt][nu][nv][nw] = 1;
          q.push_back({nm, nn, no, np, nq, nr, ns, nt, nu, nv, nw});
          cnt += 1;
        }
      }
    }
    if(cnt == prevcnt) unable = 1;
  }
  printf("%d\n", unable ? -1 : day);
}
