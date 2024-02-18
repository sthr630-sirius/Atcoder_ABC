a, b, x = map(int, input().split())
def price(n):
    p = a*n + b*len(str(n))
    return p
def is_ok(n, key):
    if price(n) <= key:
        return True
    else:
        return False
def binary_search(key):
    l = 1
    r = 10**9
    mid = (l+r)//2
    while r-l > 1:
        mid = (l+r) // 2
        if is_ok(mid, key):
            l = mid
        else:
            r = mid

    print(l)

if x >= price(10**9):
    print(10**9)
elif x < price(1):
    print(0)
else:
    binary_search(x)

