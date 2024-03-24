n = int(input())
s = input()
s1 = ""
s0 = ""
cost = list(map(int, input().split()))

cost1 = [0]*n
cost0 = [0]*n
if s[0] == "0":
    cost1[0] = cost[0]
    cost0[0] = 0
else:
    cost1[0] = 0
    cost0[0] = cost[0]

for i in range(len(s)):
    if i%2 == 0:
        s1 += "1"
    else:
        s1 += "0"
for i in range(len(s)):
    if i%2 == 0:
        s0 += "0"
    else:
        s0 += "1"
s_bit = int(s, 2)
s1_bit = int(s1, 2)
s0_bit = int(s0, 2)

#print(bin(s))
#print(bin(s1))
#print(bin(s0))
#print(bin(s1 ^ s_bit))

#print(bin(s_bit^s1_bit))
#print(bin(s_bit^s0_bit))

bit = s_bit^s1_bit
for i in reversed(range(0, n-1)):
    if (bit >> i ) & 1:
        cost1[n-i-1] = cost1[n-i-2] + cost[n-i-1]
    else:
        cost1[n-i-1] = cost1[n-i-2]

bit = s_bit^s0_bit
for i in reversed(range(0, n-1)):
    #print(f"i:{i}")
    #print(f"n-i:{n-i-1}")
    if (bit >> i ) & 1:
        #print(i)
        cost0[n-i-1] = cost0[n-i-2] + cost[n-i-1]
    else:
        cost0[n-i-1] = cost0[n-i-2]

ans = 1000000000000000

for i in range(n-1):
    s1_i1 = s[i+1]
    if s1_i1 != s[i+1]:
        ans = min(ans, cost1[i] + cost[i+1] + (cost0[n-1]-cost0[i+1]))
    else:
        ans = min(ans, cost1[i] + (cost0[n-1]-cost0[i+1]))

for i in range(n-1):
    s0_i1 = s[i+1]
    if s0_i1 != s[i+1]:
        ans = min(ans, cost0[i] + cost[i+1] + (cost1[n-1]-cost1[i+1]))
    else:
        ans = min(ans, cost0[i] + (cost1[n-1]-cost1[i+1]))

print(ans)