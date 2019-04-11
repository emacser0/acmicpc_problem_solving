#include <cstdio>
#include <cstring>
int n,p[1001],cache[1001],sum;
void merge(int s,int m,int e) {
  int i=s,j=m+1,cache_i=s;
  while(i<=m&&j<=e) {
    cache[cache_i++]=p[p[i]<p[j]?i++:j++];
  }
  while(i<=m) {
    cache[cache_i++]=p[i++];
  }
  while(j<=e) {
    cache[cache_i++]=p[j++];
  }
  for(int i=s;i<=e;i++) {
    p[i]=cache[i];
  }
  memcpy(p+s,cache+s,sizeof(int)*(e-s+1));
}
void merge_sort(int s,int e) {
  int m;
  if(s<e) {
    m=(s+e)/2;
    merge_sort(s,m);
    merge_sort(m+1,e);
    merge(s,m,e);
  }
}
int
main() {
  scanf("%d",&n);
  for(int i=0;i<n;i++) {
    scanf("%d",&p[i]);
  }
  merge_sort(0,n-1);
  for(int i=0;i<n;i++) {
    for(int j=0;j<=i;j++) {
      sum+=p[j];
    }
  }
  printf("%d\n",sum);
}
