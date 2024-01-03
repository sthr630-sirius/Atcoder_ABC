n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
ans = [0] * n

all_monster = sum(a)
#print(f"city {1}")
monster = max(a[0]-b[0], 0)
solder = max(b[0]-a[0], 0)
a[0] = monster
b[0] = solder
#print(a)
#print(b)

for i in range(1, n):
    #print(f"city {i+1}")
    monster = max(a[i]-b[i-1], 0)
    solder = max(b[i-1]-a[i], 0)
    a[i] = monster
    b[i-1] = solder
    monster = max(a[i]-b[i], 0)
    solder = max(b[i]-a[i], 0)
    a[i] = monster
    b[i] = solder
    #print(a)
    #print(b)

#print(f"city {n+1}")
monster = max(a[n]-b[n-1], 0)
solder = max(b[n-1]-a[n], 0)
a[n] = monster
b[n-1] = solder
#print(a)
#print(b)

ans = all_monster - sum(a)
#print(f"ans: {ans}")
print(ans)