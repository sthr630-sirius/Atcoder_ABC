n, d, p = map(int, input().split())
f = list(map(int, input().split()))

f.sort(reverse=True)

total_fee = 0

if d == 1:
    for i in range(n):
        total_fee += min(p, f[i])
else:
    d_day_fee = f[0]

    for i in range(1, n):
        d_day_fee += f[i]

        if (i+1)%d == 0:
            total_fee += min(p, d_day_fee)
            d_day_fee = 0

    total_fee += min(p, d_day_fee)

print(total_fee)