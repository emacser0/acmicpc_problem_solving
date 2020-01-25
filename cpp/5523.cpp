#include <cstdio>
int main()
{
    int N, A = 0, B = 0;
    scanf("%d", &N);
    {
        int a, b;
        for(int i = 0; i < N; ++i)
        {
            scanf("%d %d", &a, &b);
            A += a > b;
            B += a < b;
        }
    }
    printf("%d %d\n", A, B);
}