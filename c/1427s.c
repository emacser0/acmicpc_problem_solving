i,m=11;c[11];main(n){for(scanf("%d",&n);n;n/=10){c[n%10]++;}for(i=m-1;i>=0;i--)for(;c[i];c[i]--)printf("%d",i);}
