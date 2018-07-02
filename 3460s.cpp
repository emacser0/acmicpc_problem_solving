#include <bits/stdc++.h>
using namespace std;int n,buf,cnt;int main(){cin>>n;for(int i=0;i<n;puts(""),cnt=0,i++)for(cin>>buf;buf>0;buf>>=1,cnt++)if(buf&1)printf("%d ",cnt);
}
