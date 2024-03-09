n = int(input())
a = list(map(int, input().split()))
m = int(input())
b = list(map(int, input().split()))
l = int(input())
c = list(map(int, input().split()))
q = int(input())
x = list(map(int, input().split()))

sum_dict = {}
for i in range(n):
    for j in range(m):
        for k in range(l):
            key = a[i]+b[j]+c[k]
            sum_dict[key] = "yes"

for i in range(q):
    key = x[i]
    if key in sum_dict:
        print("Yes")
    else:
        print("No")