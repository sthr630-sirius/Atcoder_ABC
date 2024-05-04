n, x, y, z = map(int, input().split())
s = min(x, y)
e = max(x, y)
if s<= z and z <= e:
    print("Yes")
else:
    print("No")