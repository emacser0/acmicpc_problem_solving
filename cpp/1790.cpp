#include <stdio.h>
#include <string.h>
#include <math.h>
#define ll long long
#define rpow10(a) round(pow(10,a))
ll n,k,acdp[99];
char d[500];
int dg(ll x) {
  ll t=x,m=0;
  while(t) {
    t/=10;
    m++;
  }
  return m;
}
void acinit(ll x) {
  acdp[1]=9;
  for(int i=2;i<=x;i++) {
    acdp[i]=acdp[i-1]+9*i*rpow10(i-1);
  }
}
ll ac_n(ll x) {
  int m=dg(x);
  return acdp[m]+m*(x-rpow10(m)+1);
}
int main() {
  scanf("%d%d",&n,&k);
  acinit(dg(n+1));
  int m=0,r=0,i=k/10,s=-1;
  for(;i<n;i++) {
    m=dg(i),r=ac_n(i);
    if(r>=k-m){
      r-=m;
      break;
    }
  }
  int max=ac_n(n);
  while(k<=max&&r<k) {
    sprintf(d,"%d",i);
    for(int j=0;d[j]!='\0';j++) {
      r++;
      if(r==k) {
        s=d[j]-'0';
        break;
      }
    }
    i++;
  }
  printf("%d\n",s);
}
