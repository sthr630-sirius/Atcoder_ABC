n = int(input())
row = [0]*n
column = [0]*n
field = [list(input()) for _ in range(n)]

for i in range(n):
    for j in range(n):
        if field[i][j] == "o":
            row[i] += 1

for j in range(n):
    for i in range(n):
        if field[i][j] == "o":
            column[j] += 1

print(row)
print(column)

"""
TLE code

n = int(input())
field = [list(input()) for _ in range(n)]
circle_num = [[[0, 0] for _ in range(n)] for _ in range(n)]

ans = 0

#type L
for i in range(n):
    s = 0
    for j in reversed(range(n)):
        if field[i][j] == "o":
            s += 1
            circle_num[i][j][0] = s-1

for j in range(n):
    s = 0
    for i in reversed(range(n)):
        if field[i][j] == "o":
            s += 1
            circle_num[i][j][1] = s-1

for i in range(n):
    for j in range(n):
        ans += circle_num[i][j][0]* circle_num[i][j][1]

#type

for i in range(n):
    s = 0
    for j in range(n):
        if field[i][j] == "o":
            s += 1
            circle_num[i][j][0] = s-1

for j in range(n):
    s = 0
    for i in reversed(range(n)):
        if field[i][j] == "o":
            s += 1
            circle_num[i][j][1] = s-1

for i in range(n):
    for j in range(n):
        ans += circle_num[i][j][0]* circle_num[i][j][1]
        
#type

for i in range(n):
    s = 0
    for j in reversed(range(n)):
        if field[i][j] == "o":
            s += 1
            circle_num[i][j][0] = s-1

for j in range(n):
    s = 0
    for i in range(n):
        if field[i][j] == "o":
            s += 1
            circle_num[i][j][1] = s-1

for i in range(n):
    for j in range(n):
        ans += circle_num[i][j][0]* circle_num[i][j][1]

#type

for i in range(n):
    s = 0
    for j in range(n):
        if field[i][j] == "o":
            s += 1
            circle_num[i][j][0] = s-1

for j in range(n):
    s = 0
    for i in range(n):
        if field[i][j] == "o":
            s += 1
            circle_num[i][j][1] = s-1

for i in range(n):
    for j in range(n):
        ans += circle_num[i][j][0]* circle_num[i][j][1]

print(ans)

#for i in range(n):
#    print(field[i])
#for i in range(n):
#    print(circle_num[i])
"""
