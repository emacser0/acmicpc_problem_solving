#include <cstdio>
char buf[100004];
int stick_cnt,brace_cnt;
int
main() {
  scanf("%s",buf);
  for(int i=0;buf[i]!='\0';i++) {
    if(buf[i]=='(') {
      stick_cnt++;      
      brace_cnt++;
    }
    else if(buf[i]==')') {      
      brace_cnt--;
      if(buf[i-1]=='(') {
        stick_cnt--;
        stick_cnt+=brace_cnt;
      }
    }
  }
  printf("%d\n",stick_cnt);
}
