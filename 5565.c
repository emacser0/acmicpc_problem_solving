#include <stdio.h>
int n,nb;
int main() {
    scanf("%d",&n);
    for(int i=0;i<9;i++) {
        scanf("%d",&nb);
        n-=nb;
    }
    printf("%d\n",n);
}
