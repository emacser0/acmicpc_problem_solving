#include <iostream>
#include <cstdlib>
#include <cstring>
int N, t, cipher[60], original[60];
char s[100004];
int main()
{
  std::cin >> N;
  for(int i = 0; i < N; ++i)
  {
    std::cin >> t;
    cipher[t] += 1;
  }
  std::cin.ignore();
  std::cin.getline(s, 100001);
  for(int i = 0; i < N; ++i)
  {
    if(s[i] == ' ') original[0] += 1;
    else if(isupper(s[i]))
      original[s[i] - 'A' + 1] += 1;
    else
      original[s[i] - 'a' + 27] += 1;
  }
  std::cout << (memcmp(cipher, original, sizeof(cipher)) == 0 ? "y" : "n") << "\n";
}
