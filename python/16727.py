A, B = map(int, input().split())
C, D = map(int, input().split())

a = A + D
b = B + C

if a != b:
    print(["Persepolis", "Esteghlal"][a < b])
elif D != B:
    print(["Persepolis", "Esteghlal"][D < B])
else:
    print("Penalty")