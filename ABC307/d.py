n = int(input())
s = list(input())
ans = ""

left_angle_idx = [n]
del_sect = []

for i in range(n):
    if s[i] == "(":
        left_angle_idx.append(i)
    elif s[i] == ")":
        s_idx = left_angle_idx.pop()
        if s_idx == n:
            left_angle_idx.append(n)
        else:
            e_idx = i+1
            del_sect.append([s_idx, e_idx])

del_sect.sort()

for s_idx, e_idx in del_sect:
    if s[s_idx] == "-":
        continue
    for i in range(s_idx, e_idx):
        s[i] = "-"

for i in range(n):
    if s[i] != "-":
        ans += s[i]

print(ans)