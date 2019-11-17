#include <cstdio>
#include <cstring>
#include <cctype>

char buf[204];

bool check(bool * cnt)
{
    for(int i = 0; i < 26; ++i)
    {
        if(!cnt[i]) return false;
    }
    return true;
}

int main()
{
    while(fgets(buf, 204, stdin), buf[0] != '*')
    {
        bool cnt[26] = {false, };
        for(int i = 0; i < strlen(buf); ++i)
        {
            if(isalpha(buf[i])) cnt[buf[i] - 'a'] = true;
        }
        printf("%c\n", check(cnt) ? 'Y' : 'N');
    }
}
