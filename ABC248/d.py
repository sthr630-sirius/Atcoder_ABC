"""
n = int(input())
a = list(map(int, input().split()))

q = int(input())
for _ in range(q):
    l, r, x = map(int, input().split())
    l -= 1
    r -= 1
    s = [0]*n

    if a[0] == x:
        s[0] = 1

    for i in range(1, n):
        if a[i] == x:
            s[i] = s[i-1] + 1
        else:
            s[i] = s[i-1]

    if l == 0:
        print(s[r])
    else:
        print(s[r] - s[l])
"""
def lower_idx(a, x):
    l = -1
    r = len(a)
    while l+1 < r:
        mid = (l+r) // 2
        if x <= a[mid]:
            r = mid
        else:
            l = mid
    return r

def upper_idx(a, x):
    l = 0
    r = len(a)
    while l+1 < r:
        mid = (l+r) //2
        if a[mid] <= x:
            l = mid
        else:
            r = mid
    return l

n = int(input())
a = list(map(int, input().split()))
idx = [[] for _ in range(n+1) ]

for i in range(n):
    idx[a[i]].append(i+1)

print(idx)
q = int(input())
for i in range(q):
    l, r, x = map(int, input().split())
    print(lower_idx(idx[x], r))
    print(upper_idx(idx[x], l))
    print(lower_idx(idx[x], r) - upper_idx(idx[x], l))
    print("")



