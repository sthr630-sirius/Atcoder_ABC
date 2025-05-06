n = int(input())
a = list(map(int, input().split()))
two = [0]*n
three = [0]*n
p = [0]*n

for i in range(n):
    ai = a[i]

    cnt = 0
    while ai%2 == 0:
        ai = ai // 2
        cnt += 1
    two[i] = cnt

    cnt = 0
    while ai%3 == 0:
        ai = ai // 3
        cnt += 1
    three[i] = cnt

    p[i] = ai

ans = 0

if len(set(p)) == 1:
    min_two = min(two)
    for i in range(n):
        ans += two[i] - min_two
    min_three = min(three)
    for i in range(n):
        ans += three[i] - min_three
    print(ans)
else:
    print(-1)