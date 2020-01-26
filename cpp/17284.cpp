#include <cstdio>
int main()
{
    int n, s = 0;
    while(~scanf("%d", &n))
    {
        s += n == 3 ? 1000 : n == 2 ? 800 : 500;
    }
    printf("%d\n", 5000 - s);
}