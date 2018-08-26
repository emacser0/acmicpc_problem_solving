#include <cstdio>
int t,input,m[99][2],size=1;
void fib(int n) {
    if(n>size) {
        fib(n-1),fib(n-2);
        m[n][0]=m[n-1][0]+m[n-2][0];
        m[n][1]=m[n-1][1]+m[n-2][1];
    }
}
int
main() {
    m[0][0]=1;
    m[1][1]=1;
    scanf("%d",&t);
    for(int i=0;i<t;i++) {
        scanf("%d",&input);
        if(input>size) {
            fib(input);
            size=input;
        }
        printf("%d %d\n",m[input][0],m[input][1]);
    }
}
