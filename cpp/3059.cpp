#include <stdio.h>
#include <string.h>
char s[1500];
int T,c[26],sum;
int main() {
  scanf("%d",&T);
  for(int i=0;i<T;i++) {
    scanf("%s",s);
    sum=0;
    memset(c,0,26*sizeof(int));
    for(int j=0;s[j]!='\0';j++) {
      c[s[j]-'A']=1;
    }
    for(int j=0;j<26;j++) {
      sum+=!c[j]*('A'+j);
    }
    printf("%d\n",sum);
  }
}
