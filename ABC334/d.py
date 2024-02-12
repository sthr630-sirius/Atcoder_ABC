def is_ok(arry, mid, target):
    if arry[mid] <= target:
        return True
    else:
        return False

def binary_search(arry, target):
    l = -1
    r = len(arry)
    while l+1 < r:
        mid = (r + l) // 2
        if is_ok(arry, mid, target):
            l = mid
        else:
            r = mid
    return l


n, q = map(int, input().split())
r = list(map(int, input().split()))
r.sort()
'sum_r[i] i番目までのソリを引くのに必要なトナカイの総数'
sum_r = [0]*n
sum_r[0] = r[0]
for i in range(1, n):
    sum_r[i] = sum_r[i-1] + r[i]

for _ in range(q):
    x = int(input())
    ans = binary_search(sum_r, x) + 1
    print(ans)
