#include <cstdio>
int fib[40][2];

int main()
{

    fib[0][0] = 1;
    fib[1][1] = 1;

    int T;
    scanf("%d", &T);

    for(int i = 0; i < T; ++i)
    {
        int n;
        scanf("%d", &n);

        for(int i = 2; i <= 40; ++i)
        {
            fib[i][0] = fib[i-1][0] + fib[i-2][0];
            fib[i][1] = fib[i-1][1] + fib[i-2][1];
        }

        printf("%d %d\n", fib[n][0], fib[n][1]);
    }
}
