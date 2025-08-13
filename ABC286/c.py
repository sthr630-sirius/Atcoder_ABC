n, rot_cost, repl_cost = map(int, input().split())
s = input()
max_cost = (n//2) * repl_cost

for top_start_idx in range(n):
    #print(s[top_start_idx])
    bottom_start_idx = (top_start_idx-1)%n

    rot_cnt = top_start_idx
    repl_cnt = 0

    rot_match_cnt = 0

    for i in range(n//2):
        #print(f"top char:{s[(top_start_idx+i)%n]}")
        #print(f"bottom char:{s[(bottom_start_idx-i)%n]}")
        if s[(top_start_idx+i)%n] == s[(bottom_start_idx-i)%n]:
            rot_match_cnt += 1
        repl_cnt = n//2 - rot_match_cnt

    cost = rot_cost * rot_cnt + repl_cost * repl_cnt
    max_cost = min(max_cost, cost)

print(max_cost)