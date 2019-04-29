#include <stdio.h>
int T,a,b,ch;
int main() {
  scanf("%d\n",&T);
  for(int i=0;i<T;i++) {
    scanf("%d%d\n",&a,&b);
    while((ch=getchar())!='\n') {
      putchar((a*(ch-'A')+b)%26+'A');
    }
    puts("");
  }
}
