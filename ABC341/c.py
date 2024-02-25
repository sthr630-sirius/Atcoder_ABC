h, w, n = map(int, input().split())
t = list(input())
field = [list(input()) for _ in range(h)]
#print(t)
#for i in range(h):
#    print(field[i])

ans = 0

for i in range(1, h):
    for j in range(1, w):
        if field[i][j] == ".":
            #print(f"i:{i}, j:{j}")
            now = [i, j]
            for k in range(n):
                #print(f"k:{k}")
                #print(now)

                if t[k] == "L":
                    now[1] -= 1
                elif t[k] == "R":
                    now[1] += 1
                elif t[k] == "U":
                    now[0] -= 1
                elif t[k] == "D":
                    now[0] += 1

                if field[now[0]][now[1]] == "#":
                     break

            if k == n-1 and field[now[0]][now[1]] == ".":
                #print(f"now:{now}")
                #print(f"i:{i}, j:{j} -----------")
                ans += 1

print(ans)