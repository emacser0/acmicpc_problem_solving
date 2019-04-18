#include <stdio.h>
#include <stdlib.h>
int n;
char a[9],b[9];
int
main() {
  scanf("%d\n",&n);
  for(int i=0;i<n;i++) {
    scanf("%[0-9A-Z]%*[+=]%[0-9A-Z]",a,b);
    while(getchar()!='\n');
    if(a[0]=='P')printf("skipped\n");
    else{printf("%d\n",atoi(a)+atoi(b));}
  }
}
