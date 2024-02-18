l, r = map(int, input().split())
ans = []
if r - l >= 2019:
    print(0)
else:
    for i in range(l, r):
        for j in range(i+1, r+1):
            ans.append((i*j)%2019)
    print(min(ans))
