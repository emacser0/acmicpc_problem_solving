#include <stdio.h>
int K,L,N,timer,use,usecnt,cnt,i;
char s[20004],ch;
int main() {
  scanf("%d%d%d%s",&K,&L,&N,s);
  for(;i<N;i++) {
    if(s[i]=='1') {
      timer=L;
      if(!use) usecnt++;
      if(usecnt==K) usecnt=0,use=1;
    }
    if(s[i]=='0') {
      usecnt=0;
      if(use&&timer) timer--;
      if(use&&!timer){
        timer=L;use=0;cnt++;
        printf("%d\n",i+1);
      }
    }
  }
  while(timer)
    timer--,i++;
  if(use)printf("%d\n",i);
  else if(!cnt)printf("NIKAD\n");
}
