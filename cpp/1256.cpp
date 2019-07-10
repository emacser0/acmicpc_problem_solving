#include <iostream>
#include <cstring>
int N,M,K,ri;
long long count[104][104];
char result[204];
long long Min(long long a, long long b)
{
  return a < b ? a : b;
}

long long calculate(int n, int m)
{
  if(n == 0 || m == 0)
  {
    return 1;
  }

  if(count[n][m] != -1) return count[n][m];
  count[n][m] = Min(calculate(n - 1, m) + calculate(n, m - 1), 1e9 + 1);
  return count[n][m];
}

void make_result(int n, int m, int k)
{
  if(n == 0)
  {
    for(int i = 0; i < m; ++i) result[ri++] = 'z';
    return;
  }
  if(m == 0)
  {
    for(int i = 0; i < n; ++i) result[ri++] = 'a';
    return;
  }
  int boundary = calculate(n - 1, m);
  if(k < boundary)
  {
    result[ri++] = 'a';
    make_result(n - 1, m, k);
  }
  else
  {
    result[ri++] = 'z';
    make_result(n, m - 1, k - boundary);
  }
}

int main() {
  std::cin >> N >> M >> K;
  memset(count, -1, sizeof(count));
  if(K > calculate(N, M))
  {
    std::cout << "-1\n";
  }
  else
  {
    make_result(N, M, K - 1);
    std::cout << result << "\n";
  }
}
