n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
g = [[] for _ in range(n)]
x = [-1]*n
for ai, bi in zip(a, b):
    g[ai-1].append(bi-1)
    g[bi-1].append(ai-1)

print(g)
print(x)

nxt_edge = []

nxt = 0
nxt_edge += g[nxt]
now = 0
x[now] = 0

print(nxt_edge)

while nxt_edge:
    nxt = nxt_edge.pop(0)
    if x[nxt] == -1:
        if x[now] == 0:
            x[nxt] = 1
        elif x[now] == 1:
            x[nxt] = 0
        nxt_edge += g[nxt]