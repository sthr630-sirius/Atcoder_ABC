n = int(input())
s = list(input())

ans = [""]

for c in s:
    if c == "(":
        ans.append(c)
    elif c == ")":
        if len(ans) == 1:
            ans.append(c)
        else:
            ans.pop()
    else:
        ans[-1] += c

for c in ans:
    print(c, end="")
