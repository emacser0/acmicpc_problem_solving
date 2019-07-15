#include <iostream>
#include <cstring>
#include <cmath>
char A[1004], B[1004], R[1004], asign, bsign;
template <typename T>
T Max(T a, T b) { return a > b ? a : b; }
template <typename T>
void Swap(T &a, T &b) { T t = a; a = b; b = t; }
int main()
{
  std::cin >> A >> B;
  int alen = strlen(A), blen = strlen(B);
  if(A[0] =='-')
  {
    alen -= 1;
    memmove(A, A + 1, alen * sizeof(char));
  }
  else asign = 1;
  if(B[0] == '-')
  {
    blen -= 1;
    memmove(B, B + 1, blen * sizeof(char));
  }
  else bsign = 1;
  for(int i = 0; i < alen; ++i) A[i] -= '0';
  for(int i = 0; i < blen; ++i) B[i] -= '0';
  for(int i = 0, j = alen - 1; i < j; Swap(A[i++], A[j--]));
  for(int i = 0, j = blen - 1; i < j; Swap(B[i++], B[j--]));
  for(int i = 0; i < Max(alen, blen); ++i) R[i] = A[i] + B[i];
  if(asign == bsign)
  {
    for(int i = 0; i <= 1000; ++i)
    {
      R[i] = A[i] + B[i];
    }
    for(int i = 0; i <= 1000; ++i)
    {
      if(R[i] > 9) R[i] -= 10, R[i + 1] += 1;
    }
    if(!asign)
    {
      for(int i = 0; i <= 1000; ++i)
      {
        R[i] = -R[i];
      }
    }
  }
  int e = 1001;
  while(R[e] == 0 && e > 0) e--;
  for(int i = e; i >= 0; --i)
  {
    std::cout << abs((int)R[i]);
  }
  std::cout << "\n";
}
