m=int(input())
s=input()
w=3000
for i in range(1,m+1):
 a=[[0]*99 for _ in range(i)]
 for j in range(len(s)):
  a[j%i][ord(s[j])]+=1
 w=min(w,sum([sum(d)-max(d)if d.count(0)<98 else 0 for d in a]))
print(w)