import math

def upper(a, x):
    l = -1
    r = len(a)
    while(l+1 < r):
        mid = (l+r) // 2
        if a[mid] <= x:
            l = mid
        else:
            r = mid
    return l

n = int(input())

cube_root_n = int(math.pow(n, 1/3))+1
is_prime = [True for _ in range(cube_root_n+1)]
prime = []

is_prime[0] = False
is_prime[1] = False

for i in range(2, cube_root_n+1):
    k = 2
    while i*k <= cube_root_n:
        is_prime[i*k] = False
        k += 1

for i in range(len(is_prime)):
    if is_prime[i]:
        prime.append(i)

ans = 0
for i in range(len(prime)):
    p_3 = 1
    p_3 = prime[i] * prime[i] * prime[i]
    q = n // p_3
    ans += min(i-1, upper(prime, q))+1

print(ans)