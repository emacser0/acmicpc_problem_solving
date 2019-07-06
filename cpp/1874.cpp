#include <iostream>
int n, q, cur = 1, stack[100004], stacki, r[200004], ri;
void push(int n)
{
  stack[stacki++] = n;
  ri += 1;
}
void pop()
{
  stacki -= 1;
  r[ri++] = 1;
}
int main()
{
  std::cin >> n;
  for(int i = 0; i < n; ++i)
  {
    std::cin >> q;
    while(cur <= q)
    {
      push(cur++);
    }
    if(stack[stacki - 1] != q)
    {
      break;
    }
    pop();
  }
  if(ri == n * 2)
  {
    for(int i = 0; i < ri; ++i)
    {
      std::cout << (r[i]?'-':'+');
    }
  }
  else
  {
    std::cout << "NO\n";
  }
}
