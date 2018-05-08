#include <stdio.h>

int n,nb;
long min,max;
int main() {
    scanf("%d",&n);
    scanf("%d",&nb);
    min=nb;
    max=nb;
    for(int i=1;i<n;i++) {
        scanf("%d",&nb);
        min=min<nb?min:nb;
        max=max>nb?max:nb;
    }
    printf("%ld\n",min*max);
}
