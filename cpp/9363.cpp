#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int get_first_divisor(int n)
{
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            return i;
        }
    }
    return n;
}

vector<int>& divide(int n, vector<int>& v)
{
    int divisor = get_first_divisor(n);
    if (divisor < n)
    {
        v.push_back(divisor);
        return divide(n / divisor, v);
    }
    v.push_back(n);
    return v;
}

int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a, b;
        for (int j = 0; j < n; ++j)
        {
            int v;
            cin >> v;
            a.push_back(v);
        }
        for (int j = 0; j < m; ++j)
        {
            int v;
            cin >> v;
            b.push_back(v);
        }

        vector<int> ad, bd;
        for (int j = 0; j < n; ++j)
        {
            divide(a[j], ad);
        }
        for (int j = 0; j < m; ++j)
        {
            divide(b[j], bd);
        }

        int ad_size = ad.size(), bd_size = bd.size();
        for (int j = 0; j < ad_size; ++j)
        {
            for (int k = 0; k < bd_size; ++k)
            {
                if (ad[j] == bd[k])
                {
                    ad.erase(ad.begin() + j);
                    --j, --ad_size;
                    bd.erase(bd.begin() + k);
                    --bd_size;
                    break;
                }
            }
        }
        int am = 1, bm = 1;

        for (int j = 0; j < ad_size; ++j)
        {
            am *= ad[j];
        }
        for (int j = 0; j < bd_size; ++j)
        {
            bm *= bd[j];
        }

        cout << "Case #" << i + 1 << ": " << am << " / " << bm << endl;
    }
}