#include <iostream>
int A, B, C, X, Y, price;
#define swap(a, b) {int t = a; a = b; b = t;}
int Min(int a, int b)
{
  return a < b ? a : b;
}
int Max(int a, int b)
{
  return a > b ? a : b;
}
int main()
{
  std::cin >> A >> B >> C >> X >> Y;
  int m = Min(X, Y);
  int t;
  if(X < Y)
  {
    swap(A, B);
    swap(X, Y);
  }
  if(A + B >= C * 2)
  {
    price = C * 2 * m;
    if(A >= C * 2)
    {
      price += C * 2 * (X - m);
    }
    else
    {
      price += A * (X - m);
    }
  }
  else
  {
    price = A * X + B * Y;
  }
  std::cout << price << "\n";
}
