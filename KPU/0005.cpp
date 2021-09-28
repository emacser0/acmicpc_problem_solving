#include <iostream>
#include <string>

int cnt[100004];
int candidates[100004];

void sort(int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int pivot = start;
    int left = start;
    int right = end;

    while (left < right)
    {
        while (cnt[candidates[left]] > cnt[candidates[pivot]])
        {
            ++left;
        }

        while (left < right && cnt[candidates[right]] <= cnt[candidates[pivot]])
        {
            --right;
        }

        int temp = candidates[left];
        candidates[left] = candidates[right];
        candidates[right] = temp;
    }

    int temp = candidates[left];
    candidates[left] = candidates[pivot];
    candidates[pivot] = temp;

    sort(start, left);
    sort(left + 1, end);
}

int main()
{
    int C, N;
    std::cin >> C >> N;

    for (auto i = 0; i < N; ++i)
    {
        int T;
        std::cin >> T;
        ++cnt[T];
    }

    for (auto i = 0; i < C; ++i)
    {
        candidates[i] = i + 1;
    }

    sort(0, C - 1);

    std::cout << candidates[2] << std::endl;
}