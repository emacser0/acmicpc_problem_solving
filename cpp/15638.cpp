#include <cstdio>
int n;
int prime[100001];
int
main()
{
  scanf("%d",&n);
  for (int i = 2; i * i <= 1e5; i++)
    if (!prime[i])
      for (int j = i * i; j <= 1e5; j += i)
        prime[j] = true;
  printf("%s\n",prime[n]?"No":"Yes");
}
