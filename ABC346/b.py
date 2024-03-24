w, b = map(int, input().split())
s = "wbwbwwbwbwbw"*20
#print(s)
#print(len(s))
is_ok = False
for i in range(12):
    target = s[i:i+w+b]
    w_cnt = 0
    b_cnt = 0
    for p in target:
        if p == "w":
            w_cnt += 1
        else:
            b_cnt += 1
    if w_cnt == w and b_cnt == b:
        is_ok = True

if is_ok:
    print("Yes")
else:
    print("No")