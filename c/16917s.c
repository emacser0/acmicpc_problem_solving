#define s(a,b) t=a,a=b,b=t
A,B,C,X,Y,t,m;main(){scanf("%d%d%d%d%d",&A,&B,&C,&X,&Y);m=fmin(X,Y);C*=2;X<Y?s(A,B),s(X,Y):0;printf("%d\n",(A+B>C)?C*m+(A>C?C*(X-m):A*(X-m)):A*X+B*Y);}
