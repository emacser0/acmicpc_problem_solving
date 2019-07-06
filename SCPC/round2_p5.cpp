#include <iostream>
using namespace std;
int M, N, px[500004], py[500004], cache[500004], cache2[500004];
int *arr, *arr2;
int Min(int a, int b)
{
  return a < b ? a : b;
}

int Max(int a, int b)
{
  return a > b ? a : b;
}

void merge(int s, int m, int e)
{
  int i = s, j = m + 1, k = s;
  while(i <= m && j <= e)
  {
    if(arr[i] < arr[j])
    {
      cache[k] = arr[i];
      cache2[k++] = arr2[i++];
    }
    else
    {
      cache[k] = arr[j];
      cache2[k++] = arr2[j++];
    }
  }
  while(i <= m)
  {
    cache[k] = arr[i];
    cache2[k++] = arr2[i++];
  }
  while(j <= e)
  {
    cache[k] = arr[j];
    cache2[k++] = arr2[j++];
  }
  for(int i = s; i <= e; ++i)
  {
    arr[i] = cache[i];
    arr2[i] = cache2[i];
  }
}

void real_merge_sort(int s, int e)
{
  if(s < e)
  {
    int m = (s + e) / 2;
    real_merge_sort(s, m);
    real_merge_sort(m + 1, e);
    merge(s, m, e);
  }
}

void merge_sort(int *a, int *a2, int s, int e)
{
  arr = a;
  arr2 = a2;
  real_merge_sort(s, e);
}

int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
    cin >> M >> N;
    for(int i = 0; i < N; ++i)
    {
      cin >> px[i] >> py[i];
    }
    merge_sort(px, py, 0, N - 1);
    int sum = 0;
    for(int i = 0; i < N; ++i)
    {
      int min = Min(M - px[i], M - py[i]);
      for(int j = i + 1; j < N; ++j)
      {
        if(j != i && px[i] <= px[j] && py[i] <= py[j])
        {
          if(px[i] == px[j] && py[i] <= py[j])
          {
            min = Min(min, py[j] - py[i]);
          }
          else if(py[i] == py[j] && px[i] <= px[j])
          {
            min = Min(min, px[j] - px[i]);
          }
          else if(px[i] < px[j] && py[i] < py[j])
          {
            min = Min(min, Max(px[j] - px[i], py[j] - py[i]));
          }
        }
      }
      sum += min;
    }
		cout << "Case #" << test_case+1 << endl;
		cout << sum << endl;
	}
	return 0;
}
