from collections import deque

def count_edge(g, connected_v):
    edge = 0

    for vi in connected_v:
        edge += len(g[vi])

    return edge//2

n, m = map(int, input().split())
g = [[] for _ in range(n)]
for i in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    g[a].append(b)
    g[b].append(a)

#print(g)

is_visited = [False]*n
nxt_vertices = deque()
ans = 0

for i in range(n):
    connected_v = []
    v = 1
    e = 0
    if not is_visited[i]:
        nxt_v = i
        nxt_vertices.append(nxt_v)
        is_visited[nxt_v] = True
        connected_v.append(i)

        while nxt_vertices:
            now_v = nxt_vertices.popleft()
            for nxt_v in g[now_v]:
                if not is_visited[nxt_v]:
                    nxt_vertices.append(nxt_v)
                    is_visited[nxt_v] = True
                    connected_v.append(nxt_v)

        v = len(connected_v)
        e = count_edge(g, connected_v)

        ans += (v * (v-1)//2 - e)

print(ans)