s = input()
RL_index = []
LR_index = [[0, 0]]
split_s = []
static_index = []
ans = [0]*len(s)
for i in range(len(s)-1):
    if s[i]+s[i+1] == "RL":
        RL_index.append([i, i+1])
    if s[i]+s[i+1] == "LR":
        LR_index.append([i, i+1])
LR_index.append([len(s), len(s)])
#print(s)
#print(RL_index)
#print(LR_index)
for i in range(len(LR_index)-1):
    split_s.append(s[LR_index[i][1]:LR_index[i+1][1]])
#print(split_s)
for i in range(len(split_s)):
    if (RL_index[i][0] - LR_index[i][1]) % 2 == 0:
        LR = "R"
    else:
        LR = "L"
    for j in range(len(split_s[i])):
        if LR == "R":
            static_index.append(RL_index[i][0])
            LR = "L"
        else:
            static_index.append(RL_index[i][1])
            LR = "R"
#print(static_index)
for i in range(len(static_index)):
    ans[static_index[i]] += 1
print(*ans)