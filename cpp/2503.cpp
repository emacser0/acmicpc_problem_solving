#include <stdio.h>
int N,q[199][3],qp[199][3],c;
int
main() {
  scanf("%d",&N);
  for(int i=0;i<N;i++) {
    scanf("%d%d%d",q[i],q[i]+1,q[i]+2);
    int t=q[i][0];
    qp[i][2]=t%10;t/=10;
    qp[i][1]=t%10;t/=10;
    qp[i][0]=t%10;t/=10;
  }
  for(int i=123;i<=987;i++) {
    int t=i;
    int p[3];
    p[2]=t%10;t/=10;
    p[1]=t%10;t/=10;
    p[0]=t%10;t=i;
    if(p[0]==0||p[1]==0||p[2]==0||p[0]==p[1]||p[1]==p[2]||p[0]==p[2])continue;
    int f=1,nc[10]={0,0,0,0,0,0,0,0,0,0},s,b;
    nc[p[0]]=1;nc[p[1]]=1;nc[p[2]]=1;
    for(int j=0;j<N;j++) {
      s=(qp[j][0]==p[0])+(qp[j][1]==p[1])+(qp[j][2]==p[2]);
      b=nc[qp[j][0]]+nc[qp[j][1]]+nc[qp[j][2]]-s;
      b=b<0?0:b;
      if(s!=q[j][1]||b!=q[j][2]){
        f=0;
        break;
      }
    }
    if(f)c++;
  }
  printf("%d\n",c);
}
