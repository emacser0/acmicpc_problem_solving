#include <iostream>
int a, b, set_a[500004], set_b[500004], cnt_a[500004], cache[500004];
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
  for(int x = s; x <= e; ++x)
  {
    arr[x] = cache[x];
  }
}

void merge_sort(int *arr, int s, int e)
{
  if(s < e)
  {
    int m = (s + e) / 2;
    merge_sort(arr, s, m);
    merge_sort(arr, m + 1, e);
    merge(arr, s, m, e);
  }
}

int main()
{
  std::cin >> a >> b;
  for(int i = 0; i < a; ++i)
  {
    std::cin >> set_a[i];
  }
  merge_sort(set_a, 0, a - 1);
  for(int i = 0; i < b; ++i)
  {
    std::cin >> set_b[i];
  }
  merge_sort(set_b, 0, b - 1);
  int i = 0, j = 0, l = a;
  while(i < a && j < b)
  {
    while(set_a[i] > set_b[j] && j < b) j += 1;
    if(set_a[i] == set_b[j])
    {
      cnt_a[i] = 1;
      l -= 1;
    }
    i += 1;
  }
  std::cout << l << "\n";
  for(int i = 0; i < a; ++i)
  {
    if(cnt_a[i] == 0)
    {
      std::cout << set_a[i] << " ";
    }
  }
  std::cout << "\n";
}
