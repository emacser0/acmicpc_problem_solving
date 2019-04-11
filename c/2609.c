#include <stdio.h>
int gcd(int,int);
int lcm(int,int,int);

int
main() {
    int a,b,g;
    scanf("%d %d",&a,&b);
    g=gcd(a,b);
    printf("%d\n%d\n",g,lcm(a,b,g));
}

int
gcd(int A,int B) {
    int a=A,b=B,r=B;
    for(;b!=0;) {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int
lcm(int a,int b,int g) {
    return a*b/g;
}
