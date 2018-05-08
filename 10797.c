#include <stdio.h>
int n,b,c;
int main() {
    scanf("%d",&n);
    for(int i=0;i<5;i++) {
        scanf("%d",&b);
        c=b%10==n?c+1:c;
    }
    printf("%d\n",c);
}
