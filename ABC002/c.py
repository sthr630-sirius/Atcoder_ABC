xa, ya, xb, yb, xc, yc = map(int, input().split())
xba = xb - xa
yba = yb - ya
xca = xc - xa
yca = yc - ya
s = abs(xba*yca - yba*xca)/2
print(s)