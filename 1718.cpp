#include <cstdio>
#include <cstring>
char str[30009],key[30009];
int
main() {
  int str_len,key_len;
  fgets(str, 30002, stdin);
  scanf("%s",key);
  str_len=strlen(str),key_len=strlen(key);
  if(str[str_len-1]=='\n') {
    str[str_len-1]='\0',str_len--;
  }
  for(int i=0;i<str_len;i++) {
    if(str[i]==' ') {
      putchar(' ');
    }
    else {
      int value = str[i]-key[i%key_len]-1;
      while(value<0) {
        value+='z'-'a'+1;
      }
      printf("%c",value%('z'-'a'+1)+'a');
    }
  }
  puts("");
}
