t,n,x,y,i;char a[7<<14],b[7<<14];main(){for(scanf("%d",&t);x=y=0,~scanf("%d%s%s",&n,a,b);printf("%d\n",x+y-(x<y?x:y)))for(i=0;i<n;++i)x+=a[i]=='W'&&b[i]=='B',y+=a[i]=='B'&&b[i]=='W';}
