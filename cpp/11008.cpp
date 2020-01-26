#include <cstdio>
#include <cstring>
int main()
{
    int T;
    for(scanf("%d", &T); T; --T)
    {
        char s[10004], p[104];
        scanf("%s %s", s, p);
        int slen = strlen(s), plen = strlen(p);
        int cnt = 0;
        for(int i = 0; i < slen; ++cnt)
        {
            if(strncmp(s + i, p, plen) == 0) i += plen;
            else ++i;
        }
        printf("%d\n", cnt);
    }
}