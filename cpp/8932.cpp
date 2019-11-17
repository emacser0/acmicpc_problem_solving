#include <cstdio>
#include <cmath>

double A[7] = {9.23076, 1.84523, 56.0211, 4.99087, 0.188807, 15.9803, 0.11193};
double B[7] = {26.7, 75.0, 1.5, 42.5, 210.0, 3.8, 254.0};
double C[7] = {1.835, 1.348, 1.05, 1.81, 1.41, 1.04, 1.88};
int main()
{
    int T;
    scanf("%d%*[\n]", &T);
    while(T--)
    {
        int score = 0;
        for(int i = 0; i < 7; ++i)
        {
            int P;
            scanf("%d", &P);
            score += (int)(A[i] * pow(abs(B[i] - P), C[i]));
        }
        printf("%d\n", score);
    }
}