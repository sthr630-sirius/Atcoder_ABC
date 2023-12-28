n, m = map(int, input().split())
const =  1000000007
step = [0]*(n+1)
step_info = [1]*(n+1)
step[0] = 1
step[1] = 1
for i in range(m):
    a = int(input())
    step_info[a] = 0
for i in range(2, n+1):
    step[i] = ((step[i-2] * step_info[i-2])%const+ (step[i-1] * step_info[i-1])%const)%const
print(step[-1])