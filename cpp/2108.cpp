#include <cstdio>
#include <cstdlib>
#define swap(a,b) {int t=a;a=b;b=t;}
int n,nums[500004],sum,cnt[8004],max=-4000,min=4000;
int cmp(const void *a,const void *b) {
  int ra=*(int*)a,rb=*(int*)b;
  if(ra>rb) return 1;
  else if(ra<rb) return -1;
  else return 0;
}
int round(double x,double a) {
  double r=x/a;
  if(r>=0) {
    if(int(r+0.5)==(int)r+1) return r+1;
    else return r;
  }
  else {
    if(int(r-0.5)==(int)r-1) return r-1;
    else return r;
  }
  
}
int
main() {
  scanf("%d",&n);  
  for(int i=0;i<n;i++) {
    scanf("%d",nums+i);
    sum+=nums[i];
    cnt[nums[i]+4000]++;
    max=max>nums[i]?max:nums[i];
    min=min<nums[i]?min:nums[i];
  }
  qsort(nums,n,sizeof(int),cmp);
  int mcnt=0;
  for(int i=0;i<=max+4000;i++) {
    mcnt=mcnt>cnt[i]?mcnt:cnt[i];
  }
  int mcnt_stack[500004],mi=0;
  for(int i=0;i<=max+4000;i++) {
    if(cnt[i]==mcnt)
      mcnt_stack[mi++]=i-4000;
  }
  qsort(mcnt_stack,mi,sizeof(int),cmp);
  printf("%d\n",round(sum,n));
  printf("%d\n",nums[n/2]);
  if(mi<2) printf("%d\n",mcnt_stack[0]);
  else {
    printf("%d\n",mcnt_stack[1]);
  }
  printf("%d\n",max-min);  
}
