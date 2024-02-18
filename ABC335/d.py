n = int(input())
n_max = 45**2
field = [[0]*n_max for _ in range(n_max)]

field[n_max//2][n_max//2] = "T"

y = n_max//2-1
x = n_max//2
d = "r"

now_p = [y, x, d]

for i in range(1, n_max):
    y = now_p[0]
    x = now_p[1]
    d = now_p[2]
    field[y][x] = i
    if d == "r":
        if field[y+1][x] != 0:
            x += 1
        elif field[y+1][x] == 0:
            y += 1
            d = "d"
    elif d == "d":
        if field[y][x-1] != 0:
            y += 1
        elif field[y][x-1] == 0:
            x -= 1
            d = "l"
    elif d == "l":
        if field[y-1][x] != 0:
            x -= 1
        elif field[y-1][x] == 0:
            y -= 1
            d = "u"
    elif d == "u":
        if field[y][x+1] != 0:
            y -= 1
        elif field[y][x+1] == 0:
            x += 1
            d = "r"
    now_p = [y, x, d]

i_start = n_max//2 - n//2
i_end = n_max//2 + n//2
j_start = n_max//2 - n//2
j_end = n_max//2 + n//2

for i in range(i_start, i_end+1):
    print(*field[i][j_start:j_end+1])
