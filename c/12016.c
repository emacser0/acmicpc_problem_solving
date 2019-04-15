#include <stdio.h>
int n,l[100004][2],sorted[100004],si,ct,time[100004],li,nli,min,loopcnt;
void loop() {
  min=sorted[loopcnt];
  ct+=min*li;
  if(min>0) {
    for(int i=0;i<li;i++) {
      l[i][0]-=min;
    }
  }
  for(int i=0;i<li;i++) {
    printf("%d ",l[i][0]);
  }
  puts("");
  nli=0;
  for(int i=0;i<li;i++) {
    if(l[i][0]>0) {
      l[nli][0]=l[i][0];
      l[nli++][1]=l[i][1];
    }
    else {
      time[l[i][1]]=ct+i;
    }
  }
  li=nli;
  loopcnt++;
  sorted[loopcnt]-=min;
}
int t;
#define swap(a,b) {t=a;a=b;b=t;}
void insert(int x) {
  for(int i=x;i>0;i--) {
    if(sorted[i-1]>sorted[i]) {
      swap(sorted[i-1],sorted[i]);
    }
  }
}
int
main() {
  scanf("%d",&n);
  li=n;
  for(int i=0;i<n;i++) {
    scanf("%d",&l[i][0]);
    l[i][1]=i;
    sorted[i]=l[i][0];
    insert(i);
  }
  while(li) {
    loop();
  }
  for(int i=0;i<n;i++) {
    printf("%d\n",time[i]);
  }
}
