import sys
sys.setrecursionlimit(2000000)

def dfs(now_v, g, is_visited, component_info):
    is_visited[now_v] = True
    component_info[0] += 1
    component_info[1] += len(g[now_v])

    for next_v in g[now_v]:
        if not is_visited[next_v]:
            dfs(next_v, g, is_visited, component_info)
    return

n, m = map(int, input().split())
g = [[] for _ in range(n)]
for _ in range(m):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    g[u].append(v)
    g[v].append(u)


is_ok = True
is_visited = [False]*n

for now_v in range(n):
    if not is_visited[now_v]:
        component_info = [0, 0]  # first:node second:edge

        dfs(now_v, g, is_visited, component_info)

        if component_info[0]*2 == component_info[1]:
            pass
        else:
            is_ok = False

        component_info[0] = 0
        component_info[1] = 0

if is_ok:
    print("Yes")
else:
    print("No")