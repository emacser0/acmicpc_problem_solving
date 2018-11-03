n,d[10007]={1,2},i=2;main(){for(scanf("%d",&n);i<n;i++)d[i]=(d[i-2]+d[i-1])%10007;printf("%d",d[n-1]);}
