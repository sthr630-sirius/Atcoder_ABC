import math

def cal_dist(d, x, y):
    return abs(x**2+y**2-d)

d = int(input())
ans = 10**6
max_x = int(math.sqrt(d))+1

for x in range(max_x):
    y = int(math.sqrt(d - x**2))
    ans = min(ans, cal_dist(d, x, y))
    ans = min(ans, cal_dist(d, x, y+1))
    #print(f"x:{x}, y:{y}, ans:{ans}")
    #print(f"x:{x}, y:{y+1}, ans:{ans}")

print(ans)