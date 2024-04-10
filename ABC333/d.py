from collections import deque

n = int(input())
g = [[] for _ in range(n)]

for _ in range(n-1):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    g[u].append(v)
    g[v].append(u)

is_visited = [False]*n
child_v = []
child_n = []

for vi in g[0]:
    child_v.append(vi)

is_visited[0] = True

for start_v in child_v:
    nxt_vertices = deque()
    child = 0

    nxt_v = start_v
    nxt_vertices.append(nxt_v)
    is_visited[nxt_v] = True
    child += 1

    while nxt_vertices:
        now_v = nxt_vertices.popleft()
        for nxt_v in g[now_v]:
           if not is_visited[nxt_v]:
                nxt_vertices.append(nxt_v)
                is_visited[nxt_v] = True
                child += 1

    child_n.append(child)

child_n.sort()

if len(child_n) == 1:
    print(1)
else:
    print(sum(child_n[:-1])+1)