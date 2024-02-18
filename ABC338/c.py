n = int(input())
q = list(map(int, input().split()))
a = list(map(int, input().split()))
b = list(map(int, input().split()))

max_Nb = 10**6+1
for i in range(n):
    if b[i] != 0:
        tmp_b = q[i] // b[i]
        max_Nb = min(max_Nb, tmp_b)

ans = 0

for Nb in range(max_Nb+1):
    Na = 10**6+1
    for i in range(n):
        if a[i] != 0:
            tmp_a = (q[i] - b[i] * Nb) // a[i]
            Na = min(Na, tmp_a)
    ans = max(ans, Na + Nb)

print(ans)