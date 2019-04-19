#include <stdio.h>
int A,B,C;
int main() {
  scanf("%d%d%d",&A,&B,&C);
  printf("%d\n",C%2?A^B:A);
}
