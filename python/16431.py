[A, B], [C, D], [E, F] = eval('map(int, input().split(" ")),' * 3)
a = abs(E - A) ** 2 + abs(F - B) ** 2
b = (abs(E - C) + abs(F - D)) ** 2
print("bessie" if a < b else ("tie" if a == b else "daisy"))