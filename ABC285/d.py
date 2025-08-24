'''
dfs version
'''
import sys
sys.setrecursionlimit(100000000)

def find_cycle_dfs(now_v, username_table, is_visited, is_finished):
    is_visited[now_v] = True

    next_v = username_table[now_v]
    if next_v != "":
        if is_finished[next_v]:
            is_finished[now_v] = True
            return False

        if is_visited[next_v] and not is_finished[next_v]:
            return True

        if find_cycle_dfs(next_v, username_table, is_visited, is_finished):
            return True

    is_finished[now_v] = True
    return False

n = int(input())
username_table ={}
is_visited = {}
is_finished = {}

for _ in range(n):
    s, t = input().split()

    username_table[s] = t
    if t not in username_table:
        username_table[t] = ""

    is_visited[s] = False
    is_finished[s] = False
    is_visited[t] = False
    is_finished[t] = False

is_ok = True

for s in username_table:
    if not is_visited[s]:
        if find_cycle_dfs(s, username_table, is_visited, is_finished):
            is_ok = False

if is_ok:
    print("Yes")
else:
    print("No")

'''
not dfs version

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
'''