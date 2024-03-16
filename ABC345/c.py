s = input()

char_dict = {}

for key in s:
    if key in char_dict:
        char_dict[key] += 1
    else:
        char_dict[key] = 1

is_flag = False

ans = len(s)*(len(s)-1) // 2
for key in char_dict.keys():
    if char_dict[key] >= 2:
        ans -= char_dict[key]*(char_dict[key]-1)//2
        is_flag = True
if is_flag:
    print(ans+1)
else:
    print(ans)