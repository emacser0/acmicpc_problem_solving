i,m=10001;c[10001];main(n){for(scanf("%d",&n);n;n--){scanf("%d",&i);c[i]++;}for(i=1;i<m;i++)for(;c[i];c[i]--)printf("%d\n",i);}
