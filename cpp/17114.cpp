#include <iostream>
#include <vector>
#include <deque>
#include <array>
int M, N, O, P, Q, R, S, T, U, V, W, unable, empty;
int m, n, o, p, q, r, s, t, u, v, w;
using std::vector;
vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<char>>>>>>>>>>> storage;
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
std::deque<std::array<int,11>> queue;
int main()
{
  scanf("%d%d%d%d%d%d%d%d%d%d%d", &M, &N, &O, &P, &Q, &R, &S, &T, &U, &V, &W);
  for(w = 0; w < W; ++w)
  {
    storage.push_back({});
    for(v = 0; v < V; ++v)
    {
      storage[w].push_back({});
      for(u = 0; u < U; ++u)
      {
        storage[w][v].push_back({});
        for(t = 0; t < T; ++t)
        {
          storage[w][v][u].push_back({});
          for(s = 0; s < S; ++s)
          {
            storage[w][v][u][t].push_back({});
            for(r = 0; r < R; ++r)
            {
              storage[w][v][u][t][s].push_back({});
              for(q = 0; q < Q; ++q)
              {
                storage[w][v][u][t][s][r].push_back({});
                for(p = 0; p < P; ++p)
                {
                  storage[w][v][u][t][s][r][q].push_back({});
                  for(o = 0; o < O; ++o)
                  {
                    storage[w][v][u][t][s][r][q][p].push_back({});
                    for(n = 0; n < N; ++n)
                    {
                      storage[w][v][u][t][s][r][q][p][o].push_back({});
                      for(m = 0; m < M; ++m)
                      {
                        int tmp;
                        scanf("%d", &tmp);
                        storage[w][v][u][t][s][r][q][p][o][n].push_back(tmp);
                        if(tmp == 1) queue.push_back({w,v,u,t,s,r,q,p,o,n,m});
                        if(tmp == -1) empty += 1;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  cnt += queue.size();
  int day = 0;
  long long max = M * N * O * P * Q * R * S * T * U * V * W;
  while(cnt < max - empty && !unable)
  {
    day += 1;
    int size = queue.size(), prevcnt = cnt;
    while(size--)
    {
      std::array<int, 11> cur = queue.front();
      queue.pop_front();
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
           storage[nw][nv][nu][nt][ns][nr][nq][np][no][nn][nm] == 0)
        {
          storage[nw][nv][nu][nt][ns][nr][nq][np][no][nn][nm] = 1;
          queue.push_back({nw, nv, nu, nt, ns, nr, nq, np, no, nn, nm});
          cnt += 1;
        }
      }
    }
    if(cnt == prevcnt) unable = 1;
  }
  printf("%d\n", unable ? -1 : day);
}
