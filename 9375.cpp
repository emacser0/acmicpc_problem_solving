#include <cstdio>
#include <cstring>
int t,n;
int
main() {
  scanf("%d%d",&t,&n);
  for(int i=0;i<t;i++) {
    int kind_cnt[34]={0,},ki=0;
    char kind[34][24]={0,},buf[34],dummy[34];
    scanf("%d",&n);
    for(int j=0;j<n;j++) {
      scanf("%s %s",dummy,buf);
      int cond=0,k=0;
      for(;k<ki;k++) {
        if(!strcmp(buf,kind[k])) {
          cond=1;
          break;
        }
      }
      if(cond) {kind_cnt[k]++;}
      else {strcpy(kind[ki],buf);kind_cnt[ki++]++;}
    }
    int sum=1;
    for(int i=0;i<ki;i++) {
      sum*=kind_cnt[i]+1;      
    }
    sum--;
    printf("%d\n",sum);
  }
}
