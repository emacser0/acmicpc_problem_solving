#include <iostream>

int main()
{
    long long N;
    std::cin >> N;

    long long R = N / 2;
    long long R2 = R * R;
    long long cnt = 0;

    long double ph = R;
    for (long long i = 1; i < R + 1; ++i)
    {
        long long t = ph;
        long long ch = R2 - i * i;

        if ((t - 1) * (t - 1) < ch)
        {
            cnt += 1;
        }
        else
        {
            while ((t - 1) * (t - 1) >= ch && t - 1 > 0)
            {
                t -= 1;
            }

            if (t * t == ch)
            {
                cnt += ph - t;
            }
            else
            {
                cnt += ph - t + 1;
            }
        }

        ph = t;
    }

    std::cout << cnt * 4 << std::endl;
}
