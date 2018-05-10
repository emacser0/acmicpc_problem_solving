#include <stdio.h>
int woods[5];

void swap(int*,int*);

int
main() {
  
  for(int i=0;i<5;i++) {
    scanf("%d",&woods[i]);
  }
 bsort:
  for(int i=0;i<4;i++) {
    if(woods[i]>woods[i+1]) {
      swap(&woods[i],&woods[i+1]);
      for(int i=0;i<5;i++) {
        printf("%d ",woods[i]);
      }
      printf("\n");
    }
  }
  for(int i=0;i<5;i++) {
    if(woods[i]!=i+1) {
      goto bsort;
    }
  }
}

void
swap(int *a,int *b) {
  int t=*a;
  *a=*b,*b=t;
}
