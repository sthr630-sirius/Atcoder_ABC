h, w = map(int, input().split())
field = [[] for _ in range(h)]
for i in range(h):
    field[i] = list(input())

#for i in range(h):
    #print(field[i])

start_point =[]
ans = 0

dp = [[-1, -1], [-1, 0], [-1, 1], [0, -1], [0, 1], [1, -1], [1, 0], [1, 1]]

for i in range(h):
    for j in range(w):
        start_point.append([i, j])

for now_y, now_x in start_point:
    next_point = []
    if field[now_y][now_x] == "#":
        ans += 1
        #print(f"(y, x) : (", now_y, ", ", now_x, ")" )
        next_point.append([now_y, now_x])
        while next_point:
            y, x = next_point.pop(0)
            #field[y][x] = "o"
            for dy, dx in dp:
                if 0<= y+dy and y+dy<h and 0<=x+dx and x+dx<w and field[y+dy][x+dx] == "#":
                    next_point.append([y+dy, x+dx])
                    field[y+dy][x+dx] = "o"

#for i in range(h):
    #print(field[i])

print(ans)
