s = list(input())
target_idx = []
ans = []
for i in range(len(s)):
    if s[i] == "|":
        target_idx.append(i)

ans = s[:target_idx[0]] + s[target_idx[1]+1:]
print(*ans, sep="")

