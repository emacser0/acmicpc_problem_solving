i,m=1e6;main(n){int b[m],c[m*2+1];for(scanf("%d",&n);n;){scanf("%d",&b[n]);c[b[n--]+m]++;}for(;i<=m*2;i++)for(;c[i];c[i]--)printf("%d\n",i-m);}
