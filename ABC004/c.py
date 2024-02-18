n = int(input())
p = n//5%6
q = n%5

init_status_list = [[1, 2, 3, 4, 5, 6], [2, 3, 4, 5, 6, 1], [3, 4, 5, 6, 1, 2], [4, 5, 6, 1, 2, 3], [5, 6, 1, 2, 3, 4], [6, 1, 2, 3, 4, 5]]

init_status = init_status_list[p]

for i in range(q):
    a = init_status[i]
    b = init_status[i+1]
    init_status[i] = b
    init_status[i+1] = a

ans = ""
for s in init_status:
    ans += str(s)

print(ans)