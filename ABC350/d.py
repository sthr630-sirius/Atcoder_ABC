from collections import deque

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
    if not is_visited[i]:
        v = 1
        e = 0

        nxt_v = i
        nxt_vertices.append(nxt_v)
        is_visited[nxt_v] = True

        while nxt_vertices:
            now_v = nxt_vertices.popleft()
            for nxt_v in g[now_v]:
                if not is_visited[nxt_v]:
                    nxt_vertices.append(nxt_v)
                    is_visited[nxt_v] = True

                    v += 1
                    e += 1

        #print(v, e)
        if v >= 3:
            ans += (v * (v-1)//2 - e)

#print(is_visited)
print(ans)