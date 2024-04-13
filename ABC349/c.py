s = input()
t = input()
t = t.lower()

idx_0 = -1
idx_1 = -1
idx_2 = -1

n = len(s)

for i in range(n):
    if s[i] == t[0]:
        idx_0 = i
        break

if idx_0 == -1:
    print("No")
    exit()

for i in range(idx_0+1, n):
    if s[i] == t[1]:
        idx_1 = i
        break

if idx_1 == -1:
    print("No")
    exit()

#if t[2] == "x":
#    print("Yes")
#else:
for i in range(idx_1+1, n):
    if s[i] == t[2]:
        idx_2 = i
        break

if idx_2 == -1 and t[2] != "x":
    print("No")
else:
    print("Yes")
