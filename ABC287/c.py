from collections import deque

n, m = map(int, input().split())
g = [[] for _ in range(n)]
for _ in range(m):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    g[u].append(v)
    g[v].append(u)

leaf_node = []
for i in range(n):
    if len(g[i]) == 1:
        leaf_node.append(i)

if len(leaf_node) == 2:
    start_node = leaf_node[0]
    end_node = leaf_node[1]

    is_visited = [False]*n
    next_list = deque()

    next_v = start_node
    next_list.append(next_v)
    is_visited[next_v] = True
    length_node = [0]*n

    while next_list:
        now_v = next_list.popleft()
        for next_v in g[now_v]:
            if not is_visited[next_v]:
                next_list.append(next_v)
                is_visited[next_v] = True
                length_node[next_v] = length_node[now_v] + 1

    if length_node[end_node] == n-1:
        print("Yes")
    else:
        print("No")

else:
    print("No")