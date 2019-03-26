#include <cstdio>
#include <cstdlib>
int n[4];
int cmp(const void *a,const void *b) {
  int r1=*(int*)a,r2=*(int*)b;
  if(r1>r2) return 1;
  else if(r1<r2) return-1;
  else return 0;
}
int
main() {
  scanf("%d%d%d%d",n,n+1,n+2,n+3);
  qsort(n,4,sizeof(int),cmp);
  printf("%d\n",n[0]*n[2]);
}
