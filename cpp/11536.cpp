#include <cstdio>
#include <cstring>
int n;
char a[21][13],*sorted[21],*cache[21],ninc,ndec;
void
merge(int s,int m,int e) {
  int i=s,j=m+1,cache_idx=s;
  while(i<=m&&j<=e) {
    cache[cache_idx++]=sorted[strcmp(sorted[i],sorted[j])<0?i++:j++];
  }
  while(i<=m) {
    cache[cache_idx++]=sorted[i++];
  }
  while(j<=e) {
    cache[cache_idx++]=sorted[j++];
  }
  for(int i=s;i<=e;i++) {
    sorted[i]=cache[i];
  }
}
void
merge_sort(int s,int e) {
  int m=(s+e)/2;
  if(s<e) {
    merge_sort(s,m);
    merge_sort(m+1,e);
    merge(s,m,e);
  }
}
int
main() {
  scanf("%d",&n);
  for(int i=0;i<n;i++) {
    scanf("%s",a[i]);
    sorted[i]=a[i];
  }
  merge_sort(0,n-1);
  for(int i=0;i<n;i++) {
    if(strcmp(a[i],sorted[i])!=0) {
      ninc=1;
    }
    if(strcmp(a[i],sorted[n-1-i])!=0) {
      ndec=1;
    }
  }
  printf("%s\n",ninc?(ndec?"NEITHER":"DECREASING"):"INCREASING");
}
