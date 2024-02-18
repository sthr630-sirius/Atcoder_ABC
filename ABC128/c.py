n, m = map(int, input().split())

light_switch_connect = [[False]*n for _ in range(m)]
ans = 0

for i in range(m):
    for j in list(map(int, input().split()))[1:]:
        light_switch_connect[i][j-1] = True

light_on_condition = list(map(int, input().split()))

for bit in range(1<<n):
    switch_on = [False] * n
    light_switch_on = [[False] * n for _ in range(m)]
    is_light_on = [False] * m

    for i in range(n):
        if 1 & (bit>>i):
            switch_on[i] = True

    for j in range(m):
        for i in range(n):
            if light_switch_connect[j][i] and switch_on[i]:
                light_switch_on[j][i] = True

    for j in range(m):
        if sum(light_switch_on[j])%2 == light_on_condition[j]:
            is_light_on[j] = True

    if all(is_light_on):
        ans += 1

print(ans)