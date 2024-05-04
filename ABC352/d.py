n, k = map(int, input().split())
p = list(map(int, input().split()))
print(p)
num_idx = [-1]*n
for i in range(n):
    num_idx[p[i]-1] = i
print(num_idx)

target = set()
ans = 100100100100

for i in range(k):
    target.add(num_idx[i])
    ans = min(ans, target(k)-target(1))

print(target)
print(ans)

"""
for i in range(n-k+1):
    min_idx = min(num_idx[i:i+k])
    max_idx = max(num_idx[i:i+k])
    ans = min(ans, max_idx-min_idx)

print(ans)
"""