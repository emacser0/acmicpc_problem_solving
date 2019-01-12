a,b,c,d,p[101];main(){for(;a<=100;a++)p[a]=pow(a,3);for(a=2;a<=100;a++)for(b=2;b<a;b++)for(c=b;c<a;c++)for(d=c;d<a;d++)if(p[a]==p[b]+p[c]+p[d])printf("Cube = %d, Triple = (%d,%d,%d)\n",a,b,c,d);}
