#include <cstdio>
int n;
int
dsum(int n) {
    int ret=n;
    while(n!=0) {
        ret+=n-(n/10)*10;
        n/=10;
    }
    return ret;
}
int
main() {
    scanf("%d",&n);
    for(int i=0;i<=n;i++) {
        if(dsum(i)==n) {
            printf("%d\n",i);
            return 0;
        }
    }
    printf("0\n");
}
