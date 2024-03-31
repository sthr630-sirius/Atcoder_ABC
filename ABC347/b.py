s = input()
ans_s = set()
for i in range(1,  len(s)+1):
    for j in range(0, len(s)-i+1):
        #print(s[j:j+i])
        ans_s.add(s[j:j+i])

print(len(ans_s))
