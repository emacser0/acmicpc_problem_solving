#include <stdio.h>
#include <string.h>
int b,s,blen,slen;
char array_bf[2][10002]={{'0',},{'0',}};
int
main(){
  scanf("%s %s",&array_bf[0][1],&array_bf[1][1]);
  if(strlen(&array_bf[0][1])>strlen(&array_bf[1][1])) {
      b=0;
  }
  else {
      b=1;
  }
  s=!b;
  blen=strlen(array_bf[b]);
  slen=strlen(array_bf[s]);
  for(int i=slen-1;i>=1;i--) {
    array_bf[b][blen-slen+i]+=array_bf[s][i]-48;
  }
  for(int i=blen-1;i>1;i--) {
    if(array_bf[b][i]>=58) {
      array_bf[b][i]-=10;
      array_bf[b][i-1]++;
    }
  }
  if(array_bf[b][1]>=58){
    array_bf[b][1]-=10;
    array_bf[b][0]++;
    puts(array_bf[b]);
  }
  else{
    puts(&array_bf[b][1]);
  }
}
