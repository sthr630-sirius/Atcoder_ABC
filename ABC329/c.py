n = int(input())
s = input()
set_ans_string = set()

idx = 0
ans_string_head = s[idx]
ans_string_length = 1
set_ans_string.add(str(ans_string_head)+str(ans_string_length))

for i in range(1, n):
    if s[idx] == s[i]:
        ans_string_length += 1
    else:
        idx = i
        ans_string_head = s[idx]
        ans_string_length = 1
    set_ans_string.add(str(ans_string_head) + str(ans_string_length))

print(len(set_ans_string))