#include <iostream>
#include <cstring>
#include <cmath>
template <typename T>
T Max(T a, T b) { return a > b ? a : b; }
template <typename T>
void Swap(T &a, T &b) { T t = a; a = b; b = t; }

typedef struct _Big_Int
{
  char *str;
  int sign;
  int len;
} BigInt;

void Prepare(BigInt *n)
{
  if(n->str[0] =='-')
  {
    for(int i = 1; i < n->len; ++i)
      n->str[i - 1] = n->str[i], n->str[i] = 0;
    n->sign = 1, n->len -= 1;
  }
  else n->sign = 0;
  for(int i = 0; i < n->len; ++i) n->str[i] -= '0';
  for(int i = 0, j = n->len - 1; i < j; Swap(n->str[i++], n->str[j--]));
}

void Add(BigInt *a, BigInt *b, BigInt *r)
{
  memset(r->str, 0, r->len * sizeof(char));
  int mlen = Max(a->len, b->len);
  if(a->sign == b->sign)
  {
    for(int i = 0; i <= mlen; ++i)
    {
      r->str[i] += a->str[i] + b->str[i];
      if(r->str[i] > 9) r->str[i] -= 10, r->str[i + 1] += 1;
    }
    r->sign = a->sign && b->sign;
  }
  else
  {
    if(a->sign)
      for(int i = 0; i <= mlen; ++i)
        r->str[i] = b->str[i] - a->str[i];
    else
      for(int i = 0; i <= mlen; ++i)
        r->str[i] = a->str[i] - b->str[i];
    for(int i = mlen; i >= 0; --i)
      if(r->str[i] != 0)
      {
        r->sign = r->str[i] >= 0 ? 0 : 1;
        break;
      }
    if(r->sign)
      for(int i = 0; i < mlen; ++i)
      {
        if(r->str[i] > 0) r->str[i] -= 10, r->str[i + 1] += 1;
        r->str[i] = -r->str[i];
      }
    else
      for(int i = 0; i <= mlen; ++i)
        if(r->str[i] < 0) r->str[i] += 10, r->str[i + 1] -= 1;
  }
  while(r->str[r->len] == 0 && r->len > 0) r->len--;
  r->len += 1;
}

void Sub(BigInt *a, BigInt *b, BigInt *r)
{
  b->sign = !b->sign;
  Add(a, b, r);
  b->sign = !b->sign;
}

void Mul(BigInt *a, BigInt *b, BigInt *r)
{
  memset(r->str, 0, r->len * sizeof(char));
  if(a->sign == b->sign) r->sign = 0;
  else r->sign = 1;
  for(int i = 0; i < a->len; ++i)
    for(int j = 0; j < b->len; ++j)
    {
      int t = a->str[i] * b->str[j];
      for(int k = 0; k < b->str[j]; ++k)
      {
        r->str[i + j] += a->str[i];
        if(r->str[i + j] > 9) r->str[i + j + 1] += r->str[i + j] / 10, r->str[i + j] = r->str[i + j] % 10;
      }
    }
  while(r->str[r->len] == 0 && r->len > 0) r->len--;
  r->len += 1;
}

char A[10004], B[10004], R[10004];
int main()
{
  std::cin >> A >> B;
  BigInt a, b, r;
  a.str = A, a.len = strlen(A);
  b.str = B, b.len = strlen(B);
  r.str = R, r.len = 10001;
  Prepare(&a);
  Prepare(&b);
  Add(&a, &b, &r);
  if(r.sign && !(r.len == 1 && r.str[0] == 0)) std::cout << '-';
  for(int i = r.len - 1; i >= 0; --i)
    std::cout << (int)r.str[i];
  std::cout << "\n";
}
