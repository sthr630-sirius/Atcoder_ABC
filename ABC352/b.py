s = input()
t = input()
j = 0
ans = []
for i in range(len(t)):
    if t[i] == s[j]:
        ans.append(i+1)
        j += 1

print(*ans)