#include <cstdio>
int n,a[51],b[51],cache[51],*arr,mode,s;
void merge(int s,int m,int e) {
  int i=s,j=m+1,c_idx=s;
  while(i<=m&&j<=e) {
    if(mode==0) {
      cache[c_idx++]=arr[arr[i]<arr[j]?i++:j++];
    }
    else {
      cache[c_idx++]=arr[arr[i]>arr[j]?i++:j++];
    }
  }
  while(i<=m) {
    cache[c_idx++]=arr[i++];
  }
  while(j<=e) {
    cache[c_idx++]=arr[j++];
  }
  for(int i=s;i<=e;i++) {
    arr[i]=cache[i];
  }
}
void merge_sort(int s,int e) {
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
    scanf("%d",&a[i]);
  }
  for(int i=0;i<n;i++) {
    scanf("%d",&b[i]);
  }
  arr=a;
  merge_sort(0,n-1);
  arr=b,mode=1;
  merge_sort(0,n-1);
  for(int i=0;i<n;i++) {
    s+=a[i]*b[i];
  }
  printf("%d\n",s);
}
