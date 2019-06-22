#include <cstdio>
#define CHECK(x) (buf[x]!='+'&&buf[x]!='-'&&buf[x]!='\0')
#define GETN(x) for(;CHECK(x+1);x++) num=num*10+buf[x+1]-'0';
char buf[54];
int i,num,flag,sum,csum;
int
main() {
  scanf("%s",buf);
  for(;CHECK(i);i++)
    sum=sum*10+buf[i]-'0';
  for(;buf[i]!='\0';i++,num=0) {
    if(buf[i]=='+') {
      GETN(i);
      (flag?csum:sum)+=num;
    }
    else if(buf[i]=='-') {
      flag=1;
      GETN(i);
      sum-=num;
    }
  }
  printf("%d\n",sum-csum);
}

