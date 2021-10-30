N, M = map(int, input().split(" "))
print("NEWBIE!" if M < 3 else ("OLDBIE!" if M <= N else "TLE!"))