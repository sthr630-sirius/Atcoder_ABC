n = int(input())
g = [[0]*n for _ in range(n)]
ans = [[] for _ in range(n)]

for i in range(n):
    g[i] = list(map(int, input().split()))

for i in range(len(g)):
    for j in range(len(g)):
        if g[i][j] == 1:
            ans[i].append(j+1)

for ansi in ans:
    print(*ansi)
