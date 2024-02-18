n, m = map(int, input().split())
ans_l = 1
ans_r = 10**5
for _ in range(m):
    l, r = map(int, input().split())
    ans_l = max(ans_l, l)
    ans_r = min (ans_r, r)
print(max(ans_r - ans_l+1, 0))
