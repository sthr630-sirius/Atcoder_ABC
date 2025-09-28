import math

n = int(input())
comb = [0]*n

for i in range(1, n):
    sqrt_i = int(math.sqrt(i))
    cnt = 0
    for j in range(1, sqrt_i+1):
        if(i%j == 0):
            if(j == i//j):
                cnt += 1
            else:
                cnt += 2
    comb[i] = cnt

ans = 0
for i in range(1, n):
    ans += comb[i] * comb[n-i]

print(ans)