#include <cstdio>
char s[101];
int
main() {
  scanf("%s",s);
  for(auto i : s) {
    if(i>='A'&&i<='Z') {
      putchar(i);
    }
  }
  puts("");
}
// Normal Way
// int
// main() {
//   std::string str;
//   std::cin >> str;
//   for(int i=0,len=str.size();i<len;i++) {
//     std::cout << str[i];
//     for(;i<len&&str[i]!='-';i++);
//   }
//   std::cout << "\n";
// }
