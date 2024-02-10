n = int(input())
m = n
ans = 0
while n >= 1:
    n = n//2
    ans +=1

p = m*(ans+1) -2**ans

print(p)


"""
メモ再帰　コード

memo = {}

def f(n):
    print(f"f({n})")
    print(memo)
    if n == 1:
        return 0
    else:
        if n in memo:
            return memo[n]
        else:
            result = f(n // 2) + f((n + 1) // 2) + n
            memo[n] = result
            print(memo)
            return result

n = int(input())
ans = f(n)
print(ans)
"""


