#include <cstdio>
char s[9],c,b,i,j;
int
main() {
  for(;scanf("%s",s),i<8;i++,b=!b)
    for(j=0;j<8;j++,b=!b)if(!b&&s[j]=='F')c++;
  printf("%d\n",c);
}
