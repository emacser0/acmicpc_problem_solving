a,b,i,j,m=1,x,y;main(){scanf("%d%d",&a,&b);for(;m<1e7;m*=10)i=(a/m)%10,j=(b/m)%10,x+=((i==5?6:i)+(j==5?6:j))*m,y+=((i==6?5:i)+(j==6?5:j))*m;printf("%d %d\n",y,x);}
