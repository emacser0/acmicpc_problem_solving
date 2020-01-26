#include <cstdio>
bool is_available(int n)
{
    int c[10] = {0, };
    while(n)
    {
        if(c[n % 10]) return false;
        c[n % 10] = 1;
        n /= 10;
    }
    return true;
}

int main()
{
    char buf[99];
    int N, M;
    while(~scanf("%d %d", &N, &M))
    {
        int cnt = 0;
        for(int i = N; i <= M; ++i)
        {
            cnt += is_available(i);
        }
        printf("%d\n", cnt);
    }
}