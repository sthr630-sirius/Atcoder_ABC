def lower_BinarySearch(card, c):
    l = -1
    r = len(card)
    while r-l > 1:
        mid = (l + r) // 2
        #print(f"l:{l}, r:{r}, mid:{mid}, card[mid]:{card[mid]}")
        if card[mid] < c:
            l = mid
            #print("right")
        else:
            r = mid
            #print("left")
    #print(f"l:{l}, r:{r}, mid:{mid}, card[mid]:{card[mid]}")
    return r

n, m = map(int, input().split())
card = list(map(int, input().split()))

"""
TLE code
 for m
 sort n
 o(m*n)
 
for i in range(m):
    b, c = map(int, input().split())
    card.sort()
    #print(card)
    #print(f"b:{b}, c:{c}")
    p = lower_BinarySearch(card, c)
    card = [c]*min(p, b) + card[min(p, b):]
    #for j in range(min(p, b)):
    #    card[j] = c
    print(card)
    print("-------------")

print(sum(card))
"""