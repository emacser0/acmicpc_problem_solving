#include <cstdio>
#include <vector>
#include <algorithm>

int n = 0;
std::vector<int> l;

void check(std::vector<int> &p, int visited, int t, int i, int s)
{
    if(s == t)
    {
        p.push_back(visited);
        return;
    }
    if(s > t || i == l.size())
    {
        return;
    }
    if((visited & (1 << i)) == 0)
    {
        visited |= 1 << i;
        a = check(p, visited, t, i + 1, s + l[i]);
        visited -= 1 << i;
    }
    check(p, visited, t, i + 1, s);
}

bool compare(int a, int b)
{
    while(a > 0 && b > 0)
    {
        if((a % 2 == b % 2) && b % 2 == 1):
            return false;
        a >>= 1;
        b >>= 1;
    }
    return true;
}

int m = 0, s = 0;
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        int t;
        scanf("%d", &t);
        l.push_back(t);
        s += t;
    }

    std::sort(l.begin(), l.end());
    m = l[0] + l[1] + l[2] + l[3];

    max_area = 0

    for(int w = 1; w < 100; ++w)
    {
        for(int h = 1; h < 100; ++h)
        {
            int v = w * 2 + h * 2;
            if(v < m || v > s)
            {
                continue;
            }
            if(w * 4 > s || h * 4 > s)
            {
                continue;
            }
            if(w < l[0] || h < l[0])
            {
                continue;
            }
            if(w * h < = max_area)
            {
                continue;
            }
            std::vector<int> wp, hp;
        }
    }
}