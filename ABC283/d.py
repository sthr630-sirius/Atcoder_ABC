from collections import deque
s = input()
box = deque()
in_box = {}
is_ok = True

for i in range(97, 123):
    in_box[chr(i)] = False

for i in range(len(s)):
    if s[i] == "(":
        box.append(s[i])
    elif s[i] == ")":
        ball = ""
        while ball != "(":
            ball =  box.pop()
            in_box[ball] = False
    else:
        if in_box[s[i]]:
            is_ok = False
        else:
            box.append(s[i])
            in_box[s[i]] = True

if is_ok:
    print("Yes")
else:
    print("No")

"""
s = input()
n = 0
l_angle_cnt  = 0
r_angle_cnt = 0

char_dict = {}

for i in range(97, 123):
    char_dict[chr(i)] = -1

for i in range(len(s)):
    if s[i] == "(":
        n += 1

is_clear = True

for i in range(len(s)):
    if s[i] == "(":
        l_angle_cnt += 1
    elif s[i] == ")":
        l_angle_cnt -= 1
        r_angle_cnt +=1
        for j in range(97, 123):
            if char_dict[chr(j)] != -1 and char_dict[chr(j)] + r_angle_cnt == n+1:
                char_dict[chr(j)] = -1
    else:
        if char_dict[s[i]] != -1:
            is_clear = False
        else:
            char_dict[s[i]] = l_angle_cnt
    print(char_dict)

if is_clear:
    print("Yes")
else:
    print("No")
"""