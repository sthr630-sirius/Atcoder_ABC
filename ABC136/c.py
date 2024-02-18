n = int(input())
height = list(map(int, input().split()))
is_ans = True

height[0] -= 1

if n == 1:
    print("Yes")
    exit()

for i in range(1, n):
    if height[i-1] - height[i] > 0:
        is_ans = False
    elif height[i-1] - height[i] == 0:
        continue
    elif height[i-1] - height[i] < 0:
        height[i] -= 1

#print(height)

if is_ans:
    print("Yes")
else:
    print("No")