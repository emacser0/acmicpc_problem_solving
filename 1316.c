#include <stdio.h>
#include <string.h>
int gc;
int main() {
  int n;
  size_t len;
  char buf[100];  
  scanf("%d",&n);
  for(int i=0;i<n;i++) {
    char chcount[26]={0};
    scanf("%s",buf);
    len=strlen(buf);
    for(size_t i=0;i<len;i++) {
      if(i!=0&&buf[i-1]!=buf[i]) {
        if(chcount[buf[i]-'a']>0) {
          gc--;
          break;
        }
      }
      chcount[buf[i]-'a']++;
    }
    gc++;
  }
  printf("%d\n",gc);
}
