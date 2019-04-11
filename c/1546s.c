n,i,buf[1000];main(){float max,avg=0;for(scanf("%d",&n);i<n;i++){scanf("%d",&buf[i]);max=buf[i]>max?buf[i]:max;}for(int i=0;i<n;i++){avg+=buf[i]/max*100;}avg/=n;printf("%f\n",avg);}
