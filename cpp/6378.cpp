#include <cstdio>
char n[1001];
int c;
int
main() {
  for(;;) {
    scanf("%s",n);
    if(n[0]=='0') break;
    do {
      c=0;
      for(int i=0;n[i]!='\0';i++) {
        c+=n[i]-'0';
      }
      sprintf(n,"%d",c);
    } while(c>9);
    printf("%d\n",c);
  }
}
