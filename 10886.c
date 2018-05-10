#include <stdio.h>
int c,nc,n,t;

int
main() {
  for(scanf("%d",&n);n;n--) {
    scanf("%d",&t);
    if(t)
      c++;
    else
      nc++;
  }
  printf("%s\n",c>nc?"Junhee is cute!":"Junhee is not cute!");
}
