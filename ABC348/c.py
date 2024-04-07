n = int(input())
beans = {}
for _ in range(n):
    a, c = map(int, input().split())
    if c in beans:
        beans[c] = min(beans[c], a)
    else:
        beans[c] = a

ans = 0

for key in beans:
    ans = max(ans, beans[key])

print(ans)