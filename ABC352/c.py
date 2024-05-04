n = int(input())
a = []
b = []
for i in range(n):
    ai, bi = map(int, input().split())
    a.append(ai)
    b.append(bi)

body = 0
top_idx = 0
top = b[top_idx]


for i in range(1, n):
    if body + a[top_idx] + b[i] >= body + a[i] + top:
        body += a[top_idx]
        top_idx = i
        top = b[top_idx]
    else:
        body += a[i]

ans = body + top
print(ans)
