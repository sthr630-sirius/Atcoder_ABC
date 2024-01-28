import math
n = int(input())
s_list = ["".join(sorted(list(input()))) for _ in range(n)]
s_dict = {}
#print(s_list)
ans = 0
for key in s_list:
    if key in s_dict:
        s_dict[key] += 1
    else:
        s_dict[key] = 1

for key in s_dict:
    ans += math.comb(s_dict[key], 2)

#print(s_dict)a
print(ans)