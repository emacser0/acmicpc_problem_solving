N,M=map(int,input().split())
c1=["WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"]
c2=["BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"]
l=["" for x in range(0,N)]
for i in range(N):
    l[i]=str(input())
def check(y,x,cl):
    global l
    cnt=0
    for i in range(8):
        for j in range(8):
            if l[y+j][x+i]!=cl[j][i]:
                cnt+=1
    return cnt
m=int(2e9)
for i in range(0,N-7):
    for j in range(0,M-7):
        t=min(check(i,j,c1),check(i,j,c2))
        m=m if t>m else t
print(m)
