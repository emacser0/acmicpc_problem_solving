#include <iostream>
int N, L, arr[1004], cache[1004];
void merge(int *arr, int s, int m, int e)
{
  int i = s, j = m + 1, k = s;
  while(i <= m && j <= e)
  {
    if(arr[i] < arr[j])
    {
      cache[k++] = arr[i++];
    }
    else
    {
      cache[k++] = arr[j++];
    }
  }
  while(i <= m)
  {
    cache[k++] = arr[i++];
  }
  while(j <= e)
  {
    cache[k++] = arr[j++];
  }
  for(int i = s; i <= e; ++i)
  {
    arr[i] = cache[i];
  }
}
void merge_sort(int *arr, int s, int e)
{
  if(s < e)
  {
    int m = (s + e) / 2;
    merge_sort(arr, s, m);
    merge_sort(arr, m + 1, e);
    merge(arr, s, m ,e);
  }
}
int main()
{
  std::cin >> N >> L;
  for(int i = 0; i < N; ++i)
  {
    std::cin >> arr[i];
  }
  merge_sort(arr, 0, N - 1);
  for(int i = 0; i < N && arr[i] <= L; ++i)
  {
    L += 1;
  }
  std::cout << L << "\n";
}
