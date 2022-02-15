S = input()
r = ""
e = False
if S[0] == '_' or S[len(S) - 1] == '_':
    e = True
if S[0].isupper():
    e = True
if '_' in S:
    for i in range(len(S)):
        if S[i].isupper() or S[i:i+2] == '__':
            e = True
        if i > 0 and S[i - 1] == '_':
            r += S[i].upper()
        elif S[i] != '_':
            r += S[i]
else:    
    for i in range(len(S)):
        if S[i].isupper():
            r += '_'
        r += S[i].lower()
print("Error!" if e else r)
