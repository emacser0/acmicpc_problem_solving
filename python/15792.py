from decimal import *
a,b=map(int,input().split())
a,b=Decimal(a),Decimal(b)
getcontext().prec=1000
print(a/b)
