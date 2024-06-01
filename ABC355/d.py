n = int(input())
a = []
for i in range(n):
    l, r = map(int, input().split())
    a.append([l, "l"])
    a.append([r, "r"])

a.sort()

ans = 0
l_cnt = 0

for ai in a:
    if ai[1] == "l":
        ans += l_cnt
        l_cnt += 1
    elif ai[1] == "r":
        l_cnt -= 1
print(ans)