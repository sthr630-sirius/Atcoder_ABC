Q = int(input())
ans = []
for _ in range(Q):
    q, x = map(int, input().split())
    if q == 1:
        ans.append(x)
    else:
        print(ans[-x])
