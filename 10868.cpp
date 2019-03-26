#include <cstdio>
#define MIN(a,b) (a<b?a:b)
int n,m,nums[100004],tree[262148],pair[2];
int configure(int n,int s, int e) {
  if(s==e) {    
    return tree[n]=nums[s];
  }
  int a = configure(2*n+1,s,(s+e)/2),
      b = configure(2*n+2,(s+e)/2+1,e);
  return tree[n]=MIN(a,b);
}
int min(int n,int s,int e,int l,int r) {
  if(l>e||s>r)  {
    return 2e9;
  }
  if(l<=s&&r>=e) {
    return tree[n];
  }
  int a = min(2*n+1,s,(s+e)/2,l,r),
      b = min(2*n+2,(s+e)/2+1,e,l,r);
  return MIN(a,b);
}
int
main() {  
  scanf("%d%d",&n,&m);
  for(int i=0;i<n;i++) {
    scanf("%d",nums+i);
  }
  configure(0,0,n-1);
  for(int i=0;i<m;i++) {
    scanf("%d%d",pair,pair+1);
    printf("%d\n",min(0,0,n-1,pair[0]-1,pair[1]-1));
  }
}
