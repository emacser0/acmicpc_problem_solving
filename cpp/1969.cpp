#include <cstdio>
#include <cstring>
char list[1004][54];
char result_dna[54];
char table[4] = {'A', 'C', 'G', 'T'};
int min = 2e9, mini = 0;
int result_distance = 0;
int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; ++i)
    {
        scanf("%s", list[i]);
    }
    for(int i = 0; i < M; ++i)
    {
        int min_distance = 2e9, min_idx = 0;
        for(int j = 0; j < 4; ++j)
        {
            int distance = 0;
            for(int k = 0; k < N; ++k)
            {
                if(list[k][i] != table[j]) ++distance;
            }
            if(distance < min_distance)
            {
                min_distance = distance;
                min_idx = j;
            }
        }
        result_dna[i] = table[min_idx];
        result_distance += min_distance;
    }
    printf("%s\n%d\n", result_dna, result_distance);
}