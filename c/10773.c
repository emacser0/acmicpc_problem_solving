#include <stdio.h>
int k,l[100004],li,s;
int
main() {
  scanf("%d",&k);
  for(int i=0;i<k;i++) {
    scanf("%d",l+li);
    if(l[li])li++;
    else li--;
  }
  for(int i=0;i<li;i++)s+=l[i];
  printf("%d\n",s);
}
