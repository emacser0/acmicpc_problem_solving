#include <cstdio>
int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; ++i)
    {
        int a, b, c;
        char op[3];
        scanf("%d %s %d %*s %d", &a, op, &b, &c);
        printf("Case %d: %s\n", i + 1, (op[0] == '+' ? a + b : a - b) == c ? "YES" : "NO");
    }
}