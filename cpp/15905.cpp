#include <iostream>
int N, arr[99], cnt, t;
template <typename T>
void merge(T *arr, size_t s, size_t m, size_t e)
{
  static T cache[99];
  size_t i = s, j = m + 1, k = s;
  while(i <= m && j <= e)
    if(arr[i] > arr[j])
      cache[k++] = arr[i++];
    else
      cache[k++] = arr[j++];
  while(i <= m)
    cache[k++] = arr[i++];
  while(j <= e)
    cache[k++] = arr[j++];
  for(size_t x = s; x <= e; ++x)
    arr[x] = cache[x];
}
template <typename T>
void merge_sort(T *arr, size_t s, size_t e)
{
  if(s < e)
  {
    size_t m = (s + e) / 2;
    merge_sort(arr, s, m);
    merge_sort(arr, m + 1, e);
    merge(arr, s, m, e);
  }
}
int main()
{
  std::cin >> N;
  for(int i = 0; i < N; ++i)
    std::cin >> arr[i] >> t;
  merge_sort(arr, 0, N - 1);
  for(int i = 5; i < N; ++i)
    if(arr[i] == arr[4]) cnt += 1;
  std::cout << cnt << "\n";
}
