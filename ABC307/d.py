n = int(input())
s = input()
left_angle_idx = [n+1]
for i in range(n):
    if s[i] == "(":
        left_angle_idx.append(i)
    elif s[i] == ")":
        s_idx = left_angle_idx.pop()
        e_idx = i+1
        print(s[s_idx])
        print(s[e_idx])
print(s)