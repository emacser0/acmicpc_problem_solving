 #include <stdio.h>
int T,n;
int
main() {
  scanf("%d",&T);
  for(int i=0;i<T;i++) {
    scanf("%d",&n);
    printf("Pairs for %d:",n);
    for(int i=1;i<n;i++) {
      if(i>=n-i)break;
      printf(" %d %d",i,n-i);
      if(i+1<n-i-1)putchar(',');
    }
    puts("");
  }
}
