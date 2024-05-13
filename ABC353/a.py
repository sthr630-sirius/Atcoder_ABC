n = int(input())
h = list(map(int, input().split()))
h1 = h[0]
for i in range(1, n):
    if h[i] > h1:
        print(i+1)
        exit()
print(-1)