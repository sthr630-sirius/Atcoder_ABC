def gcd(x, y):
    r = x % y
    if r == 0:
        return y

    return  gcd(y, r)

n = int(input())
player_info = []

for i in range(n):
    a, b = map(int, input().split())
    p = a / (a+b)
    if a != 0 and b !=0:
        g = gcd(a, b)
        player_info.append([p, i+1, a//g, b//g])
    else:
        player_info.append([p, i+1, a, b])

#print(player_info)
player_info.sort(reverse=True)
#print(player_info)
s_idx = 0

while s_idx < n-1:
    e_idx = s_idx + 1
    cnt = 0
    while e_idx < n:
        if player_info[s_idx][0] == player_info[e_idx][0]:
            cnt += 1
            e_idx += 1
        else:
            break

    for i in range(cnt//2+1):
        #print("---")
        #print(cnt)
        #print("---")
        player_info[s_idx+i], player_info[s_idx+cnt-i] = player_info[s_idx+cnt-i], player_info[s_idx+i]

    s_idx = e_idx

for i in range(n):
    print(player_info[i][1], end=" ")

#print("")
#print(player_info)