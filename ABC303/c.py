n, m, h, k = map(int, input().split())
s = input()
items = set()
for _ in range(m):
    x, y = map(int, input().split())
    items.add((x, y))

hp = h
x = 0
y = 0
move = {"R":[1, 0], "L":[-1, 0], "U":[0, 1], "D":[0, -1]}
is_clear = True
for i in range(n):
    x += move[s[i]][0]
    y += move[s[i]][1]
    hp -= 1
    if hp < 0:
        is_clear = False
        break
    else:
        if (x, y) in items and hp < k:
            hp = k
            items.remove((x, y))

if is_clear:
    print("Yes")
else:
    print("No")