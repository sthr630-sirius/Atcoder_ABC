ans = []
while 1:
    try:
        a = input()
        ans.append(a)
    except EOFError:
        break

for a in ans[::-1]:
    print(a)