#include <iostream>

std::string stringTable[16] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};

int OctToDec(int n)
{
    int r = 0;
    int p = 1;
    while (n)
    {
        int c = n % 10;
        if (c > 7)
        {
            return 0;
        }
        
        r += c * p;

        n /= 10;
        p *= 8;
    }

    return r;
}

int HexToDec(int n)
{
    int r = 0;
    int p = 1;
    while (n)
    {
        int c = n % 10;

        r += c * p;

        n /= 10;
        p *= 16;
    }

    return r;
}

int main()
{
    int T;
    std::cin >> T;
    for (int i = 0; i < T; ++i)
    {
        int K, N;

        std::cin >> K >> N;
        std::cout << K << " " << OctToDec(N) << " " << N << " " << HexToDec(N) << std::endl;
    }
}