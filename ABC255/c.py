x, a, d, n = map(int, input().split())
a_start = min(a, a + (n-1)*d)
a_end = max(a, a + (n-1)*d)
ans = 0
#print(a_start, a_end)
if d == 0:
    ans = abs(x - a_start)
else:
    if x < a_start:
        ans = a_start -x
    elif a_end < x:
        ans = x -a_end
    elif a_start <= x <= a_end:
        m = (x - a_start)//abs(d)
        r = (x - a_start)%d
        ans = min((x - a_start) - m*abs(d), (m+1)*abs(d) - (x - a_start))
print(ans)
#print(m)