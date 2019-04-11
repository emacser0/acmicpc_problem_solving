from decimal import *
from math import ceil
a,b=map(int,input().split())
a,b=Decimal(a),Decimal(b)
if a>=0:
    print(int(a/b),a%b)
else:
    print(ceil(a/b),abs(a%b)+1)
