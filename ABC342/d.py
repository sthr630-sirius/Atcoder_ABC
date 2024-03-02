import math
n = int(input())
a = list(map(int, input().split()))

devided_pow_a =[0]*n
devided_pow_a_dict = {}

for i in range(n):
    for j in range(1, int(math.sqrt(a[i]))+1):
        if a[i]%(j*j) == 0:
            devided_pow_a[i] = a[i]//(j*j)

for key in devided_pow_a:
    if key in devided_pow_a_dict.keys():
        devided_pow_a_dict[key] += 1
    else:
        devided_pow_a_dict[key] = 1

#print(devided_pow_a_dict)

ans = 0
if 0 in devided_pow_a_dict:
    ans = ans + (n-devided_pow_a_dict[0])*devided_pow_a_dict[0] + devided_pow_a_dict[0] * (devided_pow_a_dict[0]-1)//2

tmp_ans = 0
for key in devided_pow_a:
    if key != 0:
        tmp_ans = tmp_ans + devided_pow_a_dict[key]-1

ans  = ans + tmp_ans//2

print(ans)