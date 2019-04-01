n=100000
a=input()
b=input()
q,e=int(''.join(a),2),int(''.join(b),2)
print(bin(q&e)[2:].zfill(n))
print(bin(q|e)[2:].zfill(n))
print(bin(q^e)[2:].zfill(n))
a=[0 if x else 1 for x in list(map(int,a))]
print(''.join(str(x) for x in a))
b=[0 if x else 1 for x in list(map(int,b))]
print(''.join(str(x) for x in b))
