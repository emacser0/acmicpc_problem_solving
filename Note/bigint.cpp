#include <iostream>
#include <cstring>

template <typename T>
T Max(T a, T b) { return a > b ? a : b; }
template <typename T>
void Swap(T &a, T &b) { T t = a; a = b; b = t; }

typedef struct _Big_Int
{
  int *numarray;
  int sign;
  int len;
} BigInt;

void Prepare(char *str, BigInt *n)
{
  n->len = strlen(str);
  for(int i = 0; i < n->len; ++i)
    n->numarray[i] = str[i];
  if(n->numarray[0] =='-')
  {
    for(int i = 1; i < n->len; ++i)
      n->numarray[i - 1] = n->numarray[i], n->numarray[i] = 0;
    n->sign = 1, n->len -= 1;
  }
  else n->sign = 0;
  for(int i = 0; i < n->len; ++i) n->numarray[i] -= '0';
  for(int i = 0, j = n->len - 1; i < j; Swap(n->numarray[i++], n->numarray[j--]));
}

void Add(BigInt *a, BigInt *b, BigInt *r)
{
  memset(r->numarray, 0, r->len * sizeof(char));
  int mlen = Max(a->len, b->len);
  if(a->sign == b->sign)
  {
    for(int i = 0; i <= mlen; ++i)
    {
      r->numarray[i] += a->numarray[i] + b->numarray[i];
      if(r->numarray[i] > 9) r->numarray[i] -= 10, r->numarray[i + 1] += 1;
    }
    r->sign = a->sign && b->sign;
  }
  else
  {
    if(a->sign)
      for(int i = 0; i <= mlen; ++i)
        r->numarray[i] = b->numarray[i] - a->numarray[i];
    else
      for(int i = 0; i <= mlen; ++i)
        r->numarray[i] = a->numarray[i] - b->numarray[i];
    for(int i = mlen; i >= 0; --i)
      if(r->numarray[i] != 0)
      {
        r->sign = r->numarray[i] >= 0 ? 0 : 1;
        break;
      }
    if(r->sign)
      for(int i = 0; i < mlen; ++i)
      {
        if(r->numarray[i] > 0) r->numarray[i] -= 10, r->numarray[i + 1] += 1;
        r->numarray[i] = -r->numarray[i];
      }
    else
      for(int i = 0; i <= mlen; ++i)
        if(r->numarray[i] < 0) r->numarray[i] += 10, r->numarray[i + 1] -= 1;
  }
  while(r->numarray[r->len] == 0 && r->len > 0) r->len--;
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
  memset(r->numarray, 0, r->len * sizeof(char));
  if(a->sign == b->sign) r->sign = 0;
  else r->sign = 1;
  for(int i = 0; i < a->len; ++i)
    for(int j = 0; j < b->len; ++j)
    {
      r->numarray[i + j] += a->numarray[i] * b->numarray[j];
      if(r->numarray[i + j] > 9) r->numarray[i + j + 1] += r->numarray[i + j] / 10, r->numarray[i + j] = r->numarray[i + j] % 10;
    }
  while(r->numarray[r->len] == 0 && r->len > 0) r->len--;
  r->len += 1;
}

int Cmp(BigInt *a, BigInt *b)
{
  if(!a->sign && b->sign) return 1;
  if(a->sign && !b->sign) return -1;
  int mode = (!a->sign && !b->sign) ? 1 : -1;
  if(a->len > b->len) return mode;
  if(a->len < b->len) return -mode;
  for(int i = a->len - 1; i >= 0; --i)
    if(a->numarray[i] > b->numarray[i])
      return mode;
    else if(a->numarray[i] < b->numarray[i])
      return -mode;
  return 0;
}

void Print(BigInt *n)
{
  if(n->sign && !(n->len == 1 && n->numarray[0] == 0)) std::cout << '-';
  for(int i = n->len - 1; i >= 0; --i)
    std::cout << n->numarray[i];
  std::cout << "\n";
}

char s[10004];
int A[10004], B[10004];
int main()
{
  BigInt a, b;
  std::cin >> s;
  a.numarray = A;
  Prepare(s, &a);
  std::cin >> s;
  b.numarray = B;
  Prepare(s, &b);
  std::cout << Cmp(&a, &b) << "\n";
}
