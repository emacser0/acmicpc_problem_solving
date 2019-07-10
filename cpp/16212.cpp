#include <cstdio>
#include <cstdlib>
int n,a[500004];
int cmp(const void *a,const void *b) {
  int r1=*(int*)a,r2=*(int*)b;
  if(r1>r2) return 1;
  if(r1<r2) return -1;
  return 0;
}
int main() {
  scanf("%d",&n);
  for(int i=0;i<n;i++) {
    scanf("%d",a+i);
  }
  qsort(a,n,sizeof(int),cmp);
  for(int i=0;i<n;i++) {
    printf("%d ",a[i]);
  }
  puts("");
}
