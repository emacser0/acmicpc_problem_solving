long long a,b,i,j,k;char d[8<<17];c;main(){for(scanf("%lld%lld",&a,&b),i=2;(k=i*i)<=b;++i)for(j=a/k;k*j<=b;++j)if(k*j>=a)d[k*j-a]=1;for(i=a;i<=b;++i)c=d[i-a]?c:c+1;printf("%d",c);}
