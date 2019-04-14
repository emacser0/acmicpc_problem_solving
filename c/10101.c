#include <stdio.h>
int a,b,c;
int
main() {
  scanf("%d%d%d",&a,&b,&c);
  printf("%s\n",a+b+c!=180?"Error":a==b&b==c?"Equilateral":a==b||b==c||c==a?"Isosceles":"Scalene");
}
