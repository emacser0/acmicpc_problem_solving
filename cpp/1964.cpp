#include <stdio.h>
long long n;
int main() {
  scanf("%d",&n);
  printf("%d\n",((3*n*n+5*n)/2+1)%45678);
}
