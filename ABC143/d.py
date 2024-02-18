def is_ok(array, mid, t):
    if array[mid] < t:
        return True
    else:
        return False
def binary_search(array, t):
    l = -1
    r = len(array)
    while l+1<r:
        mid = (l+r)//2
        if is_ok(array, mid, t):
            l = mid
        else:
            r = mid
    return l+1

n = int(input())
l = list(map(int, input().split()))
l.sort()

ans = 0

for i in range(n):
    for j in range(i+1, n-1):
        p = binary_search(l[j+1:], l[i]+l[j])
        ans += p

print(ans)
