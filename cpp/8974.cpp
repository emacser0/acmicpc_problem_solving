#include <cstdio>
int calc(int n)
{
    int sum = 0;
    for(int i = 1; n; ++i)
        for(int j = 0; j < i && n; ++j, --n)
            sum += i;
    return sum;
}
int main()
{
    int A, B;
    scanf("%d %d", &A, &B);
    printf("%d\n", calc(B) - calc(A - 1));
}