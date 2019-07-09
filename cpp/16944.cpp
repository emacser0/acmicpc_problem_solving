#include <iostream>
#include <cstdlib>
int N, l, u, n, s;
char S[104], sl[20] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '+'};
int Max(int a, int b)
{return a > b ? a : b;}
int main()
{
  std::cin >> N >> S;
  for(int i = 0; i < N; ++i)
    if(islower(S[i]) > 0) l = true;
    else if(isupper(S[i]) > 0) u = true;
    else if(isdigit(S[i]) > 0) n = true;
    else
    {
      if(s == true) continue;
      for(int j = 0; j < 12; ++j)
        if(S[i] == sl[j])
        {
          s = true;
          break;
        }
    }
  std::cout << Max(Max(0, 6 - N), !l + !u + !n+ !s) << "\n";
}
