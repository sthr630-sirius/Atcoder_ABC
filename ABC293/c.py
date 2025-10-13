import sys
sys.setrecursionlimit(1000000)

happy_path_num = 0

def dfs(now_y, now_x, a, track_a, h, w):
    global happy_path_num

    if a[now_y][now_x] in track_a:
        return

    track_a.add(a[now_y][now_x])

    if now_y == h-1 and now_x == w-1:
        happy_path_num += 1
        track_a.remove(a[now_y][now_x])
        return

    delta = [[1, 0], [0, 1]]
    for dy, dx in delta:
        next_y = now_y + dy
        next_x = now_x + dx
        if 0 <= next_y < h and 0 <= next_x < w:
            dfs(next_y, next_x, a, track_a,  h, w)

    track_a.remove(a[now_y][now_x])
    return


h, w = map(int, input().split())
a = []
for _ in range(h):
    a.append(list(map(int, input().split())))

now_y = 0
now_x = 0

track_a = set()

dfs(now_y, now_x, a, track_a, h, w)

print(happy_path_num)