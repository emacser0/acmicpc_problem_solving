#include <stdio.h>
int r,w,l,i;
int main() {
  while(scanf("%d",&r),r) {
    i++;
    scanf("%d%d",&w,&l);
    printf("Pizza %d %s on the table.\n",i,r*r>=0.25*(w*w+l*l)?"fits":"does not fit");
  }
}
