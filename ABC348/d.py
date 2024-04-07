from collections import deque

h, w = map(int, input().split())
field = [list(input()) for _ in range(h)]
energy_field = [[0]*w for _ in range(h)]

n = int(input())
for _ in range(n):
    y, x, e = map(int, input().split())
    y -= 1
    x -= 1
    energy_field[y][x] = e

#for ei in energy_field:
#    print(ei)

for i in range(h):
    for j in range(w):
        if field[i][j] == "S":
            y0 = i
            x0 = j
        elif field[i][j] == "T":
            ye = i
            xe = j

is_visited = [[False]*w for _ in range(h)]
energy = [[0]*w for _ in range(h)]
delta = [[1, 0], [-1, 0], [0, 1], [0, -1]]

nxt_grids = deque()

y = y0
x = x0
nxt_grids.append([y, x])
is_visited[y][x] = True


while nxt_grids:
    now_grid = nxt_grids.popleft()
    ny = now_grid[0]
    nx = now_grid[1]
    for dy, dx in delta:
        y = ny + dy
        x = nx + dx
        if 0 <= y < h and 0 <= x < w and field[y][x] != "#" and energy_field[ny][nx] >= 1:
            #print(f"y:{y}, x:{x}")
            if not is_visited[y][x]:
                #print("yes")
                nxt_grids.append([y, x])
                is_visited[y][x] = True
                energy_field[y][x] = max(energy_field[y][x], energy_field[ny][nx] - 1)
            elif is_visited and energy_field[ny][nx] - 1 > energy_field[y][x]:
                nxt_grids.append([y, x])
                energy_field[y][x] = energy_field[ny][nx] - 1

            #for fi in is_visited:
            #    print(fi)
            #print("---------------")

            #for ei in energy_field:
            #    print(ei)
            #print("-----")

if is_visited[ye][xe]:
    print("Yes")
else:
    print("No")