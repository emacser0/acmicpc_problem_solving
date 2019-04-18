#include <stdio.h>
#include <ctype.h>
#define ll long long
char s[50];
ll sum;
int isp(ll x){
  for(ll i=2;i*i<=sum;i++) {
    if(!(x%i)) return 0;
  }
  return 1;
}
int main() {
  scanf("%s",s);
  for(int i=0;s[i]!='\0';i++) {
    sum+=isupper(s[i])?s[i]-'A'+27:s[i]-'a'+1;
  }
  puts(isp(sum)?"It is a prime word.":"It is not a prime word.");
}
