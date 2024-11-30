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
    l = -1
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

q = int(input())
for i in range(q):
    l, r, x = map(int, input().split())
    #print(f"l:{l}  {lower_idx(idx[x], l)}")
    #print(f"r:{r}  {upper_idx(idx[x], r)}")
    print(upper_idx(idx[x], r) - lower_idx(idx[x], l)+1)
    #print("")



