S = input()
i = 1
for ch in S:
    if ch == "A":
        i = [i, 1, 2][(i == 2) + (i == 1) * 2]
    elif ch == "B":
        i = [i, 2, 3][(i == 3) + (i == 2) * 2]
    else:
        i = [i, 1, 3][(i == 3) + (i == 1) * 2]
print(i)