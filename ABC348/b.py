n = int(input())
points = []
for i in range(n):
    x, y = map(int, input().split())
    points.append([x, y])

for i in range(n):
    ans = -1
    max_dist = 0
    for j in range(n):
        #print(points[i][0])
        #print(points[j][0])
        #print(points[i][1])
        #print(points[j][1])
        #print("------")
        dist = (points[i][0]-points[j][0])**2+(points[i][1]-points[j][1])**2
        if dist > max_dist:
            max_dist = dist
            ans = j+1
        #print(dist)
        #print(max_dist)
        #print("------------")
    print(ans)

