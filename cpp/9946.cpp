#include <stdio.h>
#include <string.h>
char s[1000];
int alpha[26],c,f;
int main() {
  while(scanf("%s",s),strcmp(s,"END")) {
    c++;
    for(int i=0;s[i]!='\0';i++) {
      alpha[s[i]-'a']++;
    }
    scanf("%s",s);
    for(int i=0;s[i]!='\0';i++) {
      alpha[s[i]-'a']--;
    }
    f=0;
    for(int i=0;i<26;i++) {
      if(alpha[i]){
        f=1;
      }
      alpha[i]=0;
    }
    printf("Case %d: ",c);
    puts(f?"different":"same");
  }
}
