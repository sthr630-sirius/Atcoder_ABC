n, k = map(int, input().split())
a = list(map(int, input().split()))
set_a = {ai for ai in a}

sum_k = k*(k+1)//2

for ai in set_a:
    if ai <= k:
        sum_k -= ai

print(sum_k)