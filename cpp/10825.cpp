#include <cstdio>
#include <cstdlib>
#include <cstring>
struct stu{
  char name[14];
  int a,b,c;  
};
int n;
stu s[100004];
int _compare(int a,int b) {
  if(a>b) return 1;
  else if(a<b) return -1;
  else return 0;
}
int compare(const void *a,const void *b) {
  stu *ra=(stu*)a,*rb=(stu*)b;
  int r1=_compare(rb->a,ra->a);
  if(!r1) {
    int r2=_compare(ra->b,rb->b);
    if(!r2) {
      int r3=_compare(rb->c,ra->c);
      if(!r3) {
        return strcmp(ra->name,rb->name);
      }
      else return r3;
    }
    else return r2;
  }
  else return r1;
}
int
main() {
  scanf("%d",&n);
  for(int i=0;i<n;i++) {
    scanf("%s%d%d%d",s[i].name,&s[i].a,&s[i].b,&s[i].c);
  }
  qsort(s,n,sizeof(stu),compare);
  for(int i=0;i<n;i++) {
    printf("%s\n",s[i].name);
  }
}
