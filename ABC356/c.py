from collections import deque

n, m, k = map(int, input().split())

key_pattern_list = [True]*2**n

for _ in range(m):
    trial_key = [False]*n
    keys = deque(list(input().split()))
    keys.popleft()
    result = keys.pop()
    #print(keys)

    for idx in keys:
        trial_key[int(idx)-1] = True

    #print(trial_key)

    for bit in range(1 << n):
        #print(f"bit:{bit}")
        #print(f"bit: {bin(bit)}")
        cnt = 0
        for i in range(n):
            if bit & (1 << i):
                if trial_key[i]:
                    #print(i)
                    cnt += 1
        #print(f"cnt:{cnt}")
        if cnt < k and result == "o":
            key_pattern_list[bit] = False
        if cnt >= k and result == "x":
            key_pattern_list[bit] = False

#print(key_pattern_list)

ans = 0
for i in range(2**n):
    if key_pattern_list[i]:
        ans += 1
print(ans)