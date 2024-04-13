s = input()
char_dict = {}
cnt_list = [0]*(len(s)+1)

for key in s:
    if key in char_dict:
        char_dict[key] += 1
    else:
        char_dict[key] = 1

for key in char_dict:
    cnt_list[char_dict[key]] += 1

is_ok = True
for i in range(1, len(s)+1):
    if cnt_list[i] == 0:
        continue
    if cnt_list[i] == 2:
        continue
    is_ok = False

if is_ok:
    print("Yes")
else:
    print("No")