def is_ok(arr, mid, target):
    if arr[mid] >= target:
        return True
    else:
        return False

def binary_search(arr, target):
    l = -1
    r = len(arr)
    while(r -l >1):
        mid = (l+r)//2
        if is_ok(arr, mid, target):
            r = mid
        else:
            l = mid

    return r

n = int(input())
a = list(map(int, input().split()))
ans = 0
a.sort()

cnt = 0

for i in range(n):
    idx = binary_search(a, 10**8 - a[i])
    if len(a) <= idx:
        continue
    elif i < idx < len(a):
        cnt = cnt + len(a)-idx
    elif  idx <= i:
        cnt = cnt + len(a)-idx-1
#print("--")
#print(cnt)
cnt = cnt//2

for i in range(n):
    ans += (n-1)*a[i]
#print(ans)
print(ans-10**8*cnt)