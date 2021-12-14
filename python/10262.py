A, B = eval('sum(map(int, input().split(" "))),' * 2)
print(["Gunnar", "Emma", "Tie"][(A == B) + (A <= B)])
