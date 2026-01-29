from itertools import permutations

n, k = map(int ,input().split())
s = input()
perm_s = set()

for t in permutations(s, len(s)):
    perm_s.add(t)

palin_cnt = 0

for t in perm_s:
    #print(t)
    for i in range(n-k+1):
        check_palin = t[i:i+k]
        #print(check_palin)
        is_palin = True
        for j in range(k//2):
            if check_palin[j] != check_palin[len(check_palin)-1-j]:
                is_palin = False
        if is_palin:
            palin_cnt += 1
            break

print(len(perm_s)-palin_cnt)