n = int(input())
l = 1
r = n
while l+1<r:
    mid = (l+r)//2
    print(f"? {mid}", flush=True)
    s = input()
    if s == "0":
        l = mid
    else:
        r = mid

print(f"! {l}")