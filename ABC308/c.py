from functools import cmp_to_key

n = int(input())
player_info = []

for i in range(n):
    a, b = map(int, input().split())
    player_info.append([a,  a+b, i+1])

#player_info.sort(key=lambda x: -x[2])

def cmp(a, b):
    p = a[0]*b[1]
    q = a[1]*b[0]
    if p<q:
        return 1
    elif p>q:
        return -1
    else:
        return 0

player_info.sort(key=cmp_to_key(cmp))

for i in range(n):
    print(player_info[i][2], end=" ")