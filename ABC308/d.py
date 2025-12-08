import sys
sys.setrecursionlimit(1000000)

def dfs(now_p, h, w, field, is_visited, idx):

    now_y, now_x = now_p
    delta = [[1, 0], [0, 1], [-1, 0], [0, -1]]
    WORD = "snuke"
    n = (idx+1)%5

    if now_y == h-1 and now_x == w-1:
        print("Yes")
        exit()
    else:
        for i in range(4):
            dy, dx = delta[i][0], delta[i][1]
            next_y, next_x = now_y + dy, now_x + dx
            next_p = [next_y, next_x]
            if next_y < 0 or next_x < 0 or h <= next_y or w <= next_x:
                continue
            if is_visited[next_y][next_x]:
                continue
            if field[next_y][next_x] != WORD[n]:
                continue
            is_visited[next_y][next_x] = True
            dfs(next_p, h, w, field, is_visited, n)

    return

h, w = map(int, input().split())
field = []
is_visited = [[False for _ in range(w)] for _ in range(h)]
for _ in range(h):
    field.append(input())

now_p = [0, 0]
is_visited[0][0] = True
dfs(now_p, h, w, field, is_visited, 0)

print("No")