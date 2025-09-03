from collections import deque

s = input()
t = input()

is_match_front = deque()
is_match_bottom = deque()

not_match_front_cnt = 0
not_match_bottom_cnt = 0

n = len(t)

for i in range(n):
    if s[-n+i] == t[i] or s[-n+i] == "?" or t[i] == "?":
        is_match_bottom.append(True)
    else:
        is_match_bottom.append(False)
        not_match_bottom_cnt += 1

if not_match_front_cnt == 0 and not_match_bottom_cnt == 0:
    print("Yes")
else:
    print("No")

for i in range(n):
    if s[i] == t[i] or s[i] == "?" or t[i] == "?":
        is_match_front.append(True)
    else:
        is_match_front.append(False)
        not_match_front_cnt += 1

    if not is_match_bottom.popleft():
        not_match_bottom_cnt -= 1

    if not_match_front_cnt == 0 and not_match_bottom_cnt == 0:
        print("Yes")
    else:
        print("No")