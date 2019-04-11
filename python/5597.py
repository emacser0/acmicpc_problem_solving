c=[0 for x in range(30)]
for i in range(28):
    c[int(input())-1]=1
for i in range(30):
    if not c[i]:
        print(i+1)
