n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = []

for i in range(m):
    c.append([i, b[i], -1])
b.sort(reverse=True)
c = sorted(c, reverse=True, key=lambda x:x[1])

idx = 0
i = 0
while idx < m:
    if a[i] <= b[idx]:
        c[idx][2] = i+1
        idx += 1
    else:
        if i < n-1:
            i += 1
        else:
            break

c = sorted(c, key=lambda x:x[0])

for i in range(m):
    print(c[i][2])