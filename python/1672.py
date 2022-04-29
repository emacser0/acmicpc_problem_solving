T={'A':0,'G':1,'C':2,'T':3}
N,S=[*open(0)]

N=int(N)-1
c=S[N]

while N:
    c="ACAGCGTAATCGGAGT"[T[S[N-1]]*4+T[c]]
    N-=1

print(c)