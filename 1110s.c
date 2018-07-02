n,cur=999,t1,t2,i=0;main(){scanf("%d",&n);for(;n!=cur;i++){if(i==0)cur=n;t1=cur-cur/10*10;t2=cur/10+t1;cur=t1*10+t2-t2/10*10;}printf("%d\n",i);}
