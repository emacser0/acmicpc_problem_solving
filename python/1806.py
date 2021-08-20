n, s = map(int, input().split(" "))

l = list(map(int, input().split(" ")))

ps = l[0]
left = 0
right = 0
minlength = n + 1
while(left <= right and right < n):
    minlength = minlength if ps < s else min(minlength, right - left + 1)
    if ps <= s and right < n - 1:
        right += 1
        ps += l[right]
    else:
        ps -= l[left]
        left += 1

print(0 if minlength == n + 1 else minlength)