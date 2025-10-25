import math
def f(a, b, n):
    return b*n+a/math.sqrt(1+n)

def g(a, b, n):
    return f(a, b, n+1)-f(a, b, n)

a, b = map(int, input().split())
n = 10**15
l = -1
r = n+1

while l+1 < r:
    mid = (l+r)//2
    if g(a, b, mid) <= 0:
        l = mid
    else:
        r = mid

print(f(a, b, r))