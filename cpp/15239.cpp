#include <iostream>
#include <cstdlib>
int T, N;
char s[34], symlist[20] = {'+','_',')','(','*','&','^','%','$','#','@','!','.','/',',',';','{','}'};
int main()
{
  std::cin >> T;
  for(int i = 0; i < T; ++i)
  {
    int lower = 0, upper = 0, digit = 0, symbol = 0;
    std::cin >> N >> s;
    for(int j = 0; j < N; ++j)
    {
      if(islower(s[j])) lower = 1;
      if(isupper(s[j])) upper = 1;
      if(isdigit(s[j])) digit = 1;
      for(int k = 0; k < 18; ++k)
        if(s[j] == symlist[k]) symbol = 1;
    }
    std::cout << (lower && upper && digit && symbol && N >= 12 ? "valid" : "invalid") << "\n";
  }
}
