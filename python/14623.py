a, b = eval("input()," * 2)
a, b = int(a, base=2), int(b, base=2)
print(bin(a * b)[2:])