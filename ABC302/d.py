def lower_bound(a, target):
    l = -1
    r = len(a)
    while l+1 < r:
        mid = (l+r)//2
        if a[mid] >= target:
            r = mid
        else:
            l = mid
    return r

def upper_bound(a, target):
    l = -1
    r = len(a)
    while l+1 < r:
        mid = (l+r)//2
        if a[mid] <= target:
            l = mid
        else:
            r = mid
    return l

n, m, d = map(int, input().split())
a = list(map(int, input().split()))
a.sort()
b = list(map(int, input().split()))
b.sort()

ans = -1

for i in range(n):
    lower_idx = lower_bound(b, a[i]-d)
    upper_idx = upper_bound(b, a[i]+d)
    if lower_idx < n and upper_idx > -1 and lower_idx <= upper_idx:
        ans = max(ans, a[i]+b[upper_idx])

print(ans)