#include <stdio.h>
#include <string.h>
int stack[10000],ti=-1,n;
char insbuf[5];

void push();
void pop();
void size();
void empty();
void top();
void doins(char[10]);

char ins[5][10]={"push","pop","size","empty","top"};
void (*fp[5])()={push,pop,size,empty,top};

int
main() {
  scanf("%d",&n);
  for(int i=0;i<n;i++) {
    scanf("%s",insbuf);
    doins(insbuf);
  }
}

void
push() {
  int n;
  scanf("%d",&n);
  ti++;
  stack[ti]=n;
}

void
pop() {
  int r;
  if(ti==-1) printf("%d\n",-1);
  else {
    r=stack[ti];
    stack[ti]=0;
    ti--;
    printf("%d\n",r);
  }
}

void
size() {
  printf("%d\n",ti+1);
}

void
empty() {
  printf("%d\n",ti==-1?1:0);
}

void
top() {
  printf("%d\n",ti>-1?stack[ti]:-1);
}

void
doins(char str[10]) {
  for(int i=0;i<5;i++) {
    if(strcmp(str,ins[i])==0) {
      fp[i]();
    }
  }
}
