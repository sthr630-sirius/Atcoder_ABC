h, w = map(int, input().split())
field = []
field.append(["."]*(w+2))
for _ in range(h):
    field.append(["."] + list(input()) +["."])
field.append(["."]*(w+2))

n = min(h, w)
delta = [[1, 1], [1, -1], [-1, 1], [-1, -1]]
x_sizes = [0] * n

x_size = 0
x_length = 0

for i in range(1, h+1):
    for j in range(1, w+1):
        yc = i
        xc = j
        x_size = n+1
        if field[yc][xc] == "#":
            for dy, dx in delta:
                x_length = 0
                y = yc + x_length * dy
                x = xc + x_length * dx
                while field[y][x] == "#":
                    x_length += 1
                    y = yc + x_length * dy
                    x = xc + x_length * dx

                x_size = min(x_size, x_length-1)

            if x_size > 0:
                x_sizes[x_size-1] += 1

print(*x_sizes)