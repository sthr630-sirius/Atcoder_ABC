n, a, b = map(int, input().split())
d = list(map(int, input().split()))
plan = []
for di in d:
    plan.append(di%(a+b))

plan.sort()

if (plan[-1] - plan[0] + 1) <= a:
    print("Yes")
else:
    print("No")
