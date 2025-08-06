n = int(input())
username_table = {}
is_visited = {}
for _ in range(n):
    s, t = input().split()
    username_table[s] = t
    is_visited[s] = False

is_ok = True

for s in username_table:
    root_name = s
    if not is_visited[s]:
        while 1:
            is_visited[s] = True
            s = username_table[s]
            if s not in username_table:
                break
            if s == root_name:
                is_ok = False
                break

if is_ok:
    print("Yes")
else:
    print("No")