#include <stdio.h>
#include <string.h>
#include <ctype.h>
int acnt[26],cnt;
char ch;
int main() {
  while(1) {
    ch=getchar();
    if(ch=='#') break;
    if(ch=='\n') {
      printf("%d\n",cnt);
      memset(acnt,0,26*sizeof(int));
      cnt=0;
    }
    else if(isalpha(ch)&&!acnt[toupper(ch)-'A']) {
      acnt[toupper(ch)-'A']=1;
      cnt++;
    }
  }
}
