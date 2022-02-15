def getIndex(s):
    m = ["000000", "001111", "010011", "011100", "100110", "101001", "110101", "111010"]
    if s in m:
        return m.index(s)
    for i in range(8):
        if sum([s[j] != m[i][j] for j in range(6)]) <= 1:
            return i
    return -1

def getStr():
    N = int(input())
    S = input()
    s = ""
    for i in range(N):
        ch = S[i * 6: (i + 1) * 6]
        index = getIndex(ch)

        if index < 0:
            return i + 1
        s += chr(ord('A') + index)
    return s

print(getStr())