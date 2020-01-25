#include <cstdio>
#include <cstring>
#include <cmath>
int main()
{
    int N;
    scanf("%d", &N);
    {
        char s[10004];
        for(int i = 0; i < N; ++i)
        {
            scanf("%s", s);
            int square_size = sqrt(strlen(s));
            for(int j = square_size - 1; j >= 0; --j)
            {
                for(int k = 0; k < square_size ; ++k)
                {
                    putchar(s[k * square_size + j]);
                }
            }
            puts("");
        }
    }
}