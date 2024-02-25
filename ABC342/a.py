s = list(input())
#print(s)
ans = s[0]
if s[0] == s[1]:
    for i in range(len(s)):
        if ans != s[i]:
            print(i+1)
            break
else:
    if s[0] == s[2]:
        print(2)
    else:
        print(1)