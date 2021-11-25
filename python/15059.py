A, B, C = map(int, input().split(" "))
D, E, F = map(int, input().split(" "))
print((D - A) * (D > A) + (E - B) * (E > B) + (F - C) * (F > C))