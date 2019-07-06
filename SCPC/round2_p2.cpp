#include <cstdio>
#include <algorithm>
using namespace std;
int N, a[5004], b[5004], cnt[5004], cnt_r[5004];
int calculate(int n)
{
	int max = 0;
	for(int i = 0; i < n; ++i)
	{
		for(int j = i; j < n; ++j)
		{
			int sum = 0;
			for(int k = i; k <= j; ++k)
			{
				if(a[k] == b[i + j - k])
				{
					sum += 1;
				}
			}
			int r = sum + (i > 0 ? cnt[i - 1] : 0) + (i < N - 1 ? cnt_r[j + 1] : 0);
			max = max > r ? max : r;
		}
	}
	return max;
}
int main(int argc, char** argv)
{
	int T, test_case;
	setbuf(stdout, NULL);
	scanf("%d",&T);
	for(test_case = 0; test_case  < T; test_case++)
	{
		scanf("%d",&N);
    fill(cnt, cnt + 5003, 0);
    for(int i = 0; i < N; ++i)
    {
			scanf("%d",a + i);
    }
    for(int i = 0; i < N; ++i)
    {
			scanf("%d", b + i);
    }
		for(int i = 0; i < N; ++i)
		{
			cnt[i] = (i > 0 ? cnt[i - 1] : 0) + (a[i] == b[i]);
			cnt_r[N - i - 1] = cnt_r[N - i] + (a[N - i - 1] == b[N - i - 1]);
		}
		printf("Case #%d\n%d\n", test_case + 1, calculate(N));
	}
	return 0;
}
