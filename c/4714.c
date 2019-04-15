#include <stdio.h>
float n;
int
main() {
  while(scanf("%f",&n),n>0) {
    printf("Objects weighing %.2f on Earth will weigh %.2f on the moon.\n",n,n*0.167);
  }
}
