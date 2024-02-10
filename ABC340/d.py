n = int(input())
inf = 1000000000000000
s_time = [inf]*(n+1)
#print(s_time)
s_time[0] = 0
s_time[1] = 0
for i in range(1, n):
    a, b, x = map(int, input().split())
    s_time[i+1] = min(s_time[i+1], a + s_time[i])
    s_time[x] = min(s_time[x], b + s_time[i])

print(s_time[n])
print(s_time)