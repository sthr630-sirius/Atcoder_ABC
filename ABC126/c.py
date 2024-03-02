n, k = map(int, input().split())
#print(n, k)
pow_count_check = [2**i for i in range(18)]
#print(pow_count_check)

p = 0

for i in range(1, n+1):
    for j in range(18):
        if k/i <= pow_count_check[j]:
            x = j
            #print(f"i:{i}, x:{j}")
            break
    p += (1/n) * (1/2)**x

print(p)