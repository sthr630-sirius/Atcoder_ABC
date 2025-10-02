n = int(input())
pos = []
for i in range(60):
    if n & (1<<i):
        pos.append(i)

for bit in range(1<<len(pos)):
    ans = 0
    for i in range(len(pos)):
        if bit & 1<<i:
            ans += 2 ** pos[i]
    print(ans)