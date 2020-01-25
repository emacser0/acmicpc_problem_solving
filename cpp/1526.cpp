#include <cstdio>
int main()
{
    int N, k = 1;
    scanf("%d", &N);
    while(k)
        for(k = N--; k % 10 == 4 | k % 10 == 7; k /= 10);
    printf("%d", N + 1);
}