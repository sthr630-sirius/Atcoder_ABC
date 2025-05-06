import sys
sys.setrecursionlimit(20000000)
def dfs(now, g, is_visited):
    #print(f"now:{now}")
    is_visited.add(now)
    if now in g:
        for next in g[now]:
            if next not in is_visited:
                dfs(next, g, is_visited)
    return

n = int(input())
g = {}
for _ in range(n):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    if a not in g:
        g[a] = [b]
    else:
        g[a].append(b)
    if b not in g:
        g[b] = [a]
    else:
        g[b].append(a)

is_visited = set()
dfs(0, g, is_visited)

print(max(is_visited)+1)