n, reversed_t = input().split()
n = int(n)
reversed_t = list(reversed_t)
#print(n)
#print(reversed_t)

ans = []

for i in range(n):
    s = list(input())
    error = 0
    if len(s) == len(reversed_t):
        for si, ti in zip(s, reversed_t):
            if si != ti:
                error += 1
                if error == 2: break

    elif len(s)+1 == len(reversed_t):
        k = 0
        l = 0
        while k<len(s):
            if s[k] != reversed_t[l]:
                error += 1
                if error == 2: break
                l += 1
            else:
                k += 1
                l += 1

    elif len(s)-1 == len(reversed_t):
        k = 0
        l = 0
        while l<len(reversed_t):
            #if i == 5: print(f"k:l, {k}, {l}")
            if s[k] != reversed_t[l]:
                error += 1
                if error == 2: break
                k += 1
            else:
                k += 1
                l += 1

    else:
        error = 2

    if error <= 1:
        ans.append(i+1)

print(len(ans))
if ans:
    print(*ans)