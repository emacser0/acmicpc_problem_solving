#include <cstdio>
#include <cstring>
int n;
typedef struct {
  int old;
  char *name;
} people;
people p[100001];
people cache[100001];
char names[100001][101];
void merge(int s,int m,int e) {
  int i=s,j=m+1,c_idx=s;
  while(i<=m&&j<=e) {
    if(p[i].old<=p[j].old) {
      cache[c_idx].old=p[i].old;
      cache[c_idx++].name=p[i++].name;
    }
    else {
      cache[c_idx].old=p[j].old;
      cache[c_idx++].name=p[j++].name;
    }
  }
  while(i<=m) {
    cache[c_idx].old=p[i].old;
    cache[c_idx++].name=p[i++].name;
  }
  while(j<=e) {
    cache[c_idx].old=p[j].old;
    cache[c_idx++].name=p[j++].name;
  }
  for(int i=s;i<=e;i++) {
    p[i].old=cache[i].old;
    p[i].name=cache[i].name;
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
    scanf("%d %s",&p[i].old,names[i]);
    p[i].name=names[i];
  }
  merge_sort(0,n-1);
  for(int i=0;i<n;i++) {
    printf("%d %s\n",p[i].old,p[i].name);
  }
}
