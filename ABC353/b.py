n, k = map(int, input().split())
a = list(map(int, input().split()))
cnt = 0

now_sheet = k
for i in range(n):
    if a[i] <= now_sheet:
        now_sheet -= a[i]
    else:
        cnt += 1
        now_sheet = k - a[i]

print(cnt+1)