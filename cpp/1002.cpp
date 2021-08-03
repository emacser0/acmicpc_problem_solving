#include <cstdio>

int main()
{
    int T;
    scanf("%d", &T);

    for(int i = 0; i < T; ++i)
    {
        int x1, y1, r1, x2, y2, r2;
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

        int d = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
        int ra = (r1 + r2) * (r1 + r2);
        int rd = (r1 - r2) * (r1 - r2);

        if(d > ra || d < rd)
        {
            printf("%d\n", 0);
        }
        else if(d == 0 && r1 == r2)
        {
            printf("%d\n", -1);
        }
        else if(d == ra || d == rd)
        {
            printf("%d\n", 1);
        }
        else
        {
            printf("%d\n", 2);
        }
    }
}
