def exp(x):
    d = 0
    while x%2 == 0:
        x = x // 2
        d += 1
    return d, x

l, r = map(int, input().split())
target = l
cnt = 0

ans = []

while target <= r:
    if target == 0:
        d = 0
        while 2**d <= r:
            d += 1
        d -= 1
        ans.append([target, target + 2**d])
        target = target + 2 ** d
        cnt += 1
        continue

    if target == r:
        break

    d, p = exp(target)
    #for i in reversed(range(d+1)):
    delta = 2 ** d
    while target+delta > r:
        #print("yes")
        d -= 1
        delta = 2 ** d

    ans.append([target, target+delta])
    #print(ans[-1][0], ans[-1][1])
    target = target + delta

    cnt += 1

print(cnt)
for a, b in ans:
    print(a, b)