n = int(input())
a = [list(input()) for _ in range(n)]
b = [list(input()) for _ in range(n)]

for i in range(n):
    for j in range(n):
        if a[i][j] != b[i][j]:
            ans_i = i+1
            ans_j = j+1

print(ans_i, ans_j)