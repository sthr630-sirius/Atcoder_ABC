n = int(input())
field = [[0]*n for _ in range(n)]

for i in range(n):
    line = input()
    for j in range(n):
        field[i][j] = int(line[j])

delta = [[0, 1], [1, 0], [0, -1], [-1, 0], [1, 1], [1, -1], [-1, 1], [-1, -1]]
ans = 0

for i in range(n):
    for j in range(n):
        for dy, dx in delta:
            num = 0
            idx_y = i
            idx_x = j
            for k in range(n):
                num += field[(idx_y)%n][(idx_x)%n] * 10**(n-k-1)
                idx_y += dy
                idx_x += dx
            ans = max(ans, num)

print(ans)