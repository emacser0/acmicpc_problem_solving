name = input()

N = int(input())
L, O, V, E = name.count('L'), name.count('O'), name.count('V'), name.count('E')
m = -1
ms = ""
for _ in range(N):
    g = input()
    gL = g.count('L') + L
    gO = g.count('O') + O
    gV = g.count('V') + V
    gE = g.count('E') + E

    p = ((gL + gO) * (gL + gV) * (gL + gE) * (gO + gV) * (gO + gE) * (gV + gE)) % 100
    if m < p or (m == p and ms > g):
        m = p
        ms = g
print(ms)
