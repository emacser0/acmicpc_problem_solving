#include <cstdio>
int n;
char a[21],b[21];
int distance(int x) {
  return x>=0?x:x+26;
}
int
main() {
  scanf("%d",&n);
  for(int i=0;i<n;i++) {
    scanf("%s %s",a,b);
    printf("Distances:");
    for(int i=0;a[i]!='\0';i++) {
      printf(" %d",distance(b[i]-a[i]));
    }
    puts("");
  }
}
