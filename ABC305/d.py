def  binary_upper(a, target):
    l = -1
    r = len(a)
    while l+1<r:
        mid = (l+r)//2
        if a[mid] <= target:
            l = mid
        else:
            r = mid

    return l

n = int(input())
a = list(map(int, input().split()))
q = int(input())

sleep_time = [0]*len(a)
for i in range(1, len(a)):
    if i%2 == 0:
        sleep_time[i] = sleep_time[i-1] + a[i]-a[i-1]
    else:
        sleep_time[i] = sleep_time[i-1]

for _ in range(q):
    l, r = map(int, input().split())
    l_upper_idx = binary_upper(a, l)
    r_upper_idx = binary_upper(a, r)
    if l_upper_idx%2 == 0:
        delta_l = 0
    else:
        delta_l = l - a[l_upper_idx]
    if r_upper_idx%2 == 0:
        delta_r = 0
    else:
        delta_r = r - a[r_upper_idx]
    print(sleep_time[r_upper_idx] - sleep_time[l_upper_idx] + delta_r - delta_l)

