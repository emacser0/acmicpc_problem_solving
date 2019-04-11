#include <cstdio>
#include <cstring>
int n,len;
int
main() {
  scanf("%d",&n);
  char ex[51],str[51];
  scanf("%s",ex);
  len = strlen(ex);
  for(int i=0;i<n-1;i++) {
    scanf("%s",str);
    for(int i=0;i<len;i++) {
      if(ex[i]!=str[i]) {
        ex[i] = '?';
      }
    }
  }
  printf("%s\n",ex);
}
