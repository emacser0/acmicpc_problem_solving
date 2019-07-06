#include <iostream>
#define For(x, s, e) for(int x = s; x < e; ++x)
int T, N, arr[100004][2], cache[100004][2], minv[100004];
void copy(int n, int t)
{
  cache[t][0] = arr[n][0];
  cache[t][1] = arr[n][1];
}

void merge(int start, int mid, int end)
{
  int i = start, j = mid + 1, k = start;
  while(i <= mid && j <= end)
  {
    if(arr[i][0] < arr[j][0])
    {
      copy(i, k);
      i += 1;
      k += 1;
    }
    else
    {
      copy(j, k);
      j += 1;
      k += 1;
    }
  }
  while(i <= mid)
  {
    copy(i, k);
    i += 1;
    k += 1;
  }
  while(j <= end)
  {
    copy(j, k);
    j += 1;
    k += 1;
  }
  For(h, start, end + 1)
  {
    arr[h][0] = cache[h][0];
    arr[h][1] = cache[h][1];
  }
}

void merge_sort(int start, int end)
{
  if(start < end)
  {
    int mid = (start + end) / 2;
    merge_sort(start, mid);
    merge_sort(mid + 1, end);
    merge(start, mid, end);
  }
}

int main()
{
  std::cin >> T;
  For(i, 0, T)
  {
    std::cin >> N;
    For(j, 0, N)
    {
      std::cin >> arr[j][0] >> arr[j][1];
    }
    merge_sort(0, N - 1);
    int cnt = 1;
    minv[0] = arr[0][1];
    For(j, 1, N)
    {
      if(arr[j][1] < minv[j - 1])
      {
        cnt += 1;
      }
      minv[j] = minv[j - 1] < arr[j][1] ? minv[j - 1] : arr[j][1];
    }
    std::cout << cnt << "\n";
  }
}
