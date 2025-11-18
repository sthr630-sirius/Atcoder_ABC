x, y, z = map(int, input().split())
s = input()
n = len(s)

inf = 1000000000000000000
dp_caps_off = [0]*(n+1)
dp_caps_on = [inf]*(n+1)

for i in range(0, n):
    if s[i] == "a":
        dp_caps_off[i+1] = min(dp_caps_off[i]+x, dp_caps_on[i]+z+x)
        dp_caps_on[i+1] = min(dp_caps_off[i]+z+y, dp_caps_on[i]+y)
    elif s[i] == "A":
        dp_caps_off[i+1] = min(dp_caps_off[i]+y, dp_caps_on[i]+z+y)
        dp_caps_on[i+1] = min(dp_caps_on[i]+x, dp_caps_off[i]+z+x)

print(min(dp_caps_off[n], dp_caps_on[n]))