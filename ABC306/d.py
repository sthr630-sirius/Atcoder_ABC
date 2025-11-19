n = int(input())
meals = [[0, 0]]
for _ in range(n):
    x, y = map(int, input().split())
    meals.append([x, y])

dp_healthy = [0]*(n+1)
dp_not_healthy = [0]*(n+1)

for i in range(1, n+1):
    if meals[i][0] == 0:
        dp_healthy[i] = max(dp_healthy[i-1]+meals[i][1], dp_healthy[i-1], dp_not_healthy[i-1]+meals[i][1])
        dp_not_healthy[i] = dp_not_healthy[i-1]
    else:
        dp_healthy[i] = dp_healthy[i-1]
        dp_not_healthy[i] = max(dp_healthy[i-1]+meals[i][1], dp_not_healthy[i-1])

print(max(dp_healthy[n], dp_not_healthy[n]))