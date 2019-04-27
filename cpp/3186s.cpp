#include <stdio.h>
int K,L,N,t,u,uc,c,i;
char s[10004],ch;
int main(){
  scanf("%d%d%d%s",&K,&L,&N,s);
  for(;i<N;i++) {
    if(s[i]=='1'&&(t=L)){
      if(!u)uc++;
      if(uc==K)uc=0,u=1;
    }
    if(s[i]=='0'&&!(uc=0)){
      if(u&&t)t--;
      if(u&&!t)t=L,u=0,c++,printf("%d\n",i+1);
    }
  }
  while(t)t--,i++;
  if(u)printf("%d\n",i);
  else if(!c)printf("NIKAD\n");
}
