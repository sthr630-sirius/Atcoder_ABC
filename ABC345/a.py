s = input()
is_ok = True
for i in range(len(s)):
    if i == 0:
        if s[i] != "<":
            is_ok = False
    elif i < len(s)-1:
        if s[i] != "=":
            is_ok = False
    elif i == len(s)-1:
        if s[i] != ">":
            is_ok = False

if is_ok:
    print("Yes")
else:
    print("No")