n = int(input())
p = [0]*n
x = [0]*n

l = [0]*n
r = [0]*n

l_sum = [0]*n
r_sum = [0]*n

for i in range(n):
    l[i], r[i] = map(int, input().split())

l_sum[0] = l[0]
r_sum[0] = r[0]

for i in range(1, n):
    l_sum[i] = l_sum[i-1] + l[i]
    r_sum[i] = r_sum[i-1] + r[i]

if l_sum[n-1]*r_sum[n-1] > 0:
    print('No')
else:
    print('Yes')
    for i in reversed(range(1, n)):
        x[i] = max(p[i]-r_sum[i-1], l[i])
        p[i-1] = p[i] - x[i]

    x[0] = p[0]

    print(*x)