#define CACHE_SIZE 10000
int cache[CACHE_SIZE];
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
