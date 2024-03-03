"""
bit brute-force code
"""
n = int(input())
like_321 = []

for bit in range(1, 1<<10):
    #print(f"num:{bit}, binary:{bin(bit)}")
    x = ""
    for i in range(10):
        if bit & (1<<i):
            x = str(i) + x
    like_321.append(int(x))

like_321.sort()

print(like_321[n])


"""
first code
passed test case

n = int(input())

like_321 = [i for i in range(10)]
sidx = 0
eidx = len(like_321)-1
counter = len(like_321)-1

for k in range(1, 10):
    for i in range(1, 10):
        for j in range(sidx, eidx+1):
            x = like_321[j]
            if i > int(str(x)[0]):
                like_321.append(int(str(i) + str(x)))
                counter += 1

    sidx = eidx+1
    eidx = len(like_321)-1

#print(like_321)
#print(f"sidx:{sidx}, eidx:{eidx}")
#print(like_321[sidx])
#print(like_321[eidx])

print(like_321[n])
"""