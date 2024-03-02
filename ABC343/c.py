n = int(input())

i = 1
ans = str(i**3)

while  i**3 <= n:
    s = str(i**3)
    t = s[::-1]
    if s == t:
        ans = s
    i += 1

print(ans)

"""
code version 1
passed test case

n = int(input())

#print(math.pow(342, 1/3))

if 8<= n and n < 343:
    print(8)

elif 1<= n and n < 8:
    print(1)

else:
    c_root_n = math.pow(n, 1/3)
    max_c_root = int(c_root_n)

    if (max_c_root+1)**3 == n:
        max_c_root = max_c_root+1

    for i in reversed(range(1, max_c_root+1)):
        x = str(i**3)
        idx = len(x)//2
        #print(f"i:{i}, x:{x}")
        #print(idx)
        front_x = x[:idx]
        back_x = x[-idx:]

        #print(front_x)
        #print(back_x)

        if front_x == back_x[::-1]:
            print(x)
            break
"""