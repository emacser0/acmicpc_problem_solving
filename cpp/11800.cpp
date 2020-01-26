#include <cstdio>
char aliases[6][10] = {"Yakk", "Doh", "Seh", "Ghar", "Bang", "Sheesh"};
char double_aliases [6][10] = {"Habb Yakk", "Dobara", "Dousa", "Dorgy", "Dabash", "Dosh"};
int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; ++i)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        if(a < b)
        {
            int t = a;
            a = b;
            b = t;
        }
        printf("Case %d: ", i + 1);
        if(a == 6 && b == 5) puts("Sheesh Beesh");
        else if(a == b) puts(double_aliases[a - 1]);
        else printf("%s %s\n", aliases[a - 1], aliases[b - 1]);
    }
}