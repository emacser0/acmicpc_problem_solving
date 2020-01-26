#include <cstdio>
int main()
{
    int x1, y1, x2, y2, x3, y3;
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
    int ax = x1 - x2, ay = y1 - y2;
    int bx = x3 - x2, by = y3 - y2;
    puts(!(ax * by - bx * ay) ? "WHERE IS MY CHICKEN?" : "WINNER WINNER CHICKEN DINNER!");
}