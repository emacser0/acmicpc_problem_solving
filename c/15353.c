#include <stdio.h>
#include <string.h>
int b,s,bl,sl,i;
char *p;

int
main(){
  char bf[2][19999]={{'0',},{'0',}};
  scanf("%s %s",&bf[0][1],&bf[1][1]);
  b=strlen(&bf[0][1])>strlen(&bf[1][1])?0:1;
  s=b==0?1:0;
  bl=strlen(bf[b]);
  sl=strlen(bf[s]);
  for(i=sl-1;i>0;i--){
    bf[b][bl-sl+i]+=bf[s][i]-48;
  }
  for(i=bl-1;i>1;i--){
    if(bf[b][i]>57){
      bf[b][i]-=10;
      bf[b][i-1]++;
    }
  }
  if(bf[b][1]>57){
    bf[b][1]-=10;
    bf[b][0]++;
    p=bf[b];
  }
  else{
    p=&bf[b][1];
  }
  puts(p);
}
