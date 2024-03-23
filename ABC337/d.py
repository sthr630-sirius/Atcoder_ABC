from collections import deque
h, w, k = map(int, input().split())
field = [list(input()) for _ in range(h)]

inf = 999999999999
ans = inf

for i in range(h):
    j = 0
    l = 0
    circle_cnt = 0
    target_erea = deque()

    while j+l < w:
        if field[i][j+l] == "x":
            j = j+l+1
            l = 0
            circle_cnt = 0
            target_erea = deque()
        else:
            target_erea.append(field[i][j+l])
            if field[i][j + l] == "o": circle_cnt += 1

            if len(target_erea) < k:
                pass

            elif len(target_erea) == k:
                ans = min(ans, k - circle_cnt)

            elif len(target_erea) > k:
                point = target_erea.popleft()
                if point == "o": circle_cnt -= 1
                ans = min(ans, k-circle_cnt)
            l += 1

            #print(target_erea)
            #print(f"circle_cnt : {circle_cnt}")
            #print(f"ans : {ans}")
            #print("---------------------------------------")

for j in range(w):
    i = 0
    l = 0
    circle_cnt = 0
    target_erea = deque()

    while i+l < h:

        if field[i+l][j] == "x":
            i = i+l+1
            l = 0
            circle_cnt = 0
            target_erea = deque()
        else:
            target_erea.append(field[i+l][j])
            if field[i+l][j] == "o": circle_cnt += 1

            if len(target_erea) < k:
                pass

            elif len(target_erea) == k:
                ans = min(ans, k - circle_cnt)

            elif len(target_erea) > k:
                point = target_erea.popleft()
                if point == "o": circle_cnt -= 1
                ans = min(ans, k-circle_cnt)
            l += 1

            #print(target_erea)
            #print(f"circle_cnt : {circle_cnt}")
            #print(f"ans : {ans}")
            #print("---------------------------------------")

if ans != inf:
    print(ans)
else:
    print(-1)