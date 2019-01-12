#include <cstdio>
int a,b,i,j,m=1,max,min;
int
main() {
  scanf("%d%d",&a,&b);
  for(;m<1e7;m*=10) {
    i=(a/m)%10,j=(b/m)%10;
    max+=((i==5?6:i)+(j==5?6:j))*m;
    min+=((i==6?5:i)+(j==6?5:j))*m;
  }
  printf("%d %d\n",min,max);
}
// String solution
// #include <cstring>
// char a[10],b[10];
// int alen,blen,max,min,mul=1,v;
// int
// main() {
//   scanf("%s%s",a,b);
//   alen=strlen(a),blen=strlen(b);
//   for(int i=alen-1;i>=0;i--,mul*=10) {
//     v = a[i]-'0';
//     max += (v==5?6:v)*mul;
//     min += (v==6?5:v)*mul;
//   }
//   for(int i=blen-1,mul=1;i>=0;i--,mul*=10) {
//     v = b[i]-'0';
//     max += (v==5?6:v)*mul;
//     min += (v==6?5:v)*mul;
//   }
//   printf("%d %d\n",min,max);
// }
