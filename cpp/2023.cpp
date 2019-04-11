#include <cstdio>
#include <cmath>
int first_table[4]={2,3,5,7};
int table[5]={1,3,5,7,9};
int n,min;
bool isprime(int x) {
  if(x<2) return false;
  for(int i=2;i*i<=x;i++)
    if(!(x%i)) return false;  
  return true;
}
void search(int x) {
  if(x>=min*10) return;
  else if(x/min>0) {
    if(isprime(x)) printf("%d\n",x);    
    return;
  }
  int t;
  for(int i=0;i<5;i++) {
    t=x*10+table[i];
    if(isprime(t)) search(t);
  }
}
void specialprime() {
  for(int i=0;i<4;i++) search(first_table[i]);
}
int
main() {
  scanf("%d",&n);
  min=pow(10,n-1);  
  specialprime();
}
