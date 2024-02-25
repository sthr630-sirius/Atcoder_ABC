n = int(input())
a = list(map(int, input().split()))
s = [0]*(n-1)
t = [0]*(n-1)
for i in range(n-1):
    s[i], t[i] = map(int, input().split())

#print(a)
#print(s)
#print(t)

for i in range(n-1):
    a[i+1] += a[i]//s[i]*t[i]

print(a[n-1])
