#include <stdio.h>
int T,stack[1004],si;
void pstack(char end) {
  for(int i=si-1;i>=0;) {
    putchar(stack[i--]);
  }
  putchar(end);
  si=0;
}
int main() {
  scanf("%d\n",&T);
  for(int i=0;i<T;i++) {
    while(1) {
      stack[si]=getchar();
      if(stack[si]=='\n') {
        pstack('\n');
        break;
      }
      else if(stack[si]==' ') {
        pstack(' ');
      }
      else {
        si++;
      }
    }
  }
}
