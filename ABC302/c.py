import itertools

def judge_semi_match(s, t):
    cnt_match = 0
    for i in range(len(s)):
        if s[i] == t[i]:
            cnt_match += 1
    if cnt_match == len(s)-1:
        is_semi_match = True
    else:
        is_semi_match = False
    return is_semi_match

n, m = map(int, input().split())
string_list = [input() for _ in range(n)]

for perm in itertools.permutations(string_list, n):
    is_ok = True
    for i in range(n-1):
        if not judge_semi_match(perm[i], perm[i+1]):
            is_ok = False
    if is_ok:
        break

if is_ok:
    print("Yes")
else:
    print("No")