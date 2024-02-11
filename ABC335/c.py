n, q = map(int, input().split())
track = [[i, 0] for i in reversed(range(1, n+1))]
now_p = track[-1]
for _ in range(q):
    now_p = track[-1]
    x = now_p[0]
    y = now_p[1]
    q1, q2 = input().split()
    if q1 == "1":
        if q2 == "U":
            y += 1
        elif q2 == "D":
            y -= 1
        elif q2 == "R":
            x += 1
        elif q2 == "L":
            x -= 1
        track.append([x, y])
    elif q1 == "2":
        p = int(q2)
        print(track[-p][0], track[-p][1])