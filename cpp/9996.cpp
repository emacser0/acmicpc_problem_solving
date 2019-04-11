#include <cstdio>
#include <cstring>
int N;
char str[104],p[104],bp[104];
int
main() {
  scanf("%d %s",&N,p);
  int plen=strlen(p),cond=0,star_i;
  for(int i=0;i<plen;i++) {
    if(p[i]=='*') {
      cond=1;
      star_i=i;
      break;
    }
  }
  for(int t=0;t<N;t++) {
    scanf("%s",str);
    int slen=strlen(str);
    if(cond) {
      p[star_i]='\0';
      for(int i=0;i+star_i+1<plen;i++) {
        bp[i]=p[i+star_i+1];
      }
      plen=strlen(p);
      int bplen=strlen(bp);
      if(!strncmp(str,p,plen)) {
        if(strlen(str+plen)<bplen) {
          printf("NE\n");
        }
        else{
          printf("%s\n",!strncmp(str+slen-bplen,bp,bplen)?"DA":"NE");
        }
      }
      else {
        printf("NE\n");
      }
    }
    else {
      printf("%s\n",!strcmp(str,p)?"DA":"NE");
    }
  }

}
