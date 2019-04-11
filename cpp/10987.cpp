#include <cstdio>
char vowels[5] = {'a','e','i','o','u'},str[101],cnt;
int
main() {
  scanf("%s",str);
  for(int i=0;str[i]!='\0';i++) {
    for(int j=0;j<5;j++) {
      if(str[i]==vowels[j]) {
        cnt++;
        break;
      }
    }
  }
  printf("%d\n",cnt);
}
