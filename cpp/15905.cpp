#include <iostream>
int N, arr[99][2], cnt;
template <typename T>
void merge(T (*arr)[2], size_t s, size_t m, size_t e)
{
  static T cache[99][2];
  size_t i = s, j = m + 1, k = s;
  while(i <= m && j <= e)
    if(arr[i][0] > arr[j][0] || (arr[i][0] == arr[j][0] && arr[i][1] > arr[j][1]))
      cache[k][0] = arr[i][0], cache[k++][1] = arr[i++][1];
    else
      cache[k][0] = arr[j][0], cache[k++][1] = arr[j++][1];
  while(i <= m)
    cache[k][0] = arr[i][0], cache[k++][1] = arr[i++][1];
  while(j <= e)
    cache[k][0] = arr[j][0], cache[k++][1] = arr[j++][1];
  for(size_t x = s; x <= e; ++x)
    arr[x][0] = cache[x][0], arr[x][1] = cache[x][1];
}
template <typename T>
void merge_sort(T (*arr)[2], size_t s, size_t e)
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
    std::cin >> arr[i][0] >> arr[i][1];
  merge_sort(arr, 0, N - 1);
  for(int i = 5; i < N; ++i)
    if(arr[i][0] == arr[4][0]) cnt += 1;
  std::cout << cnt << "\n";
}
