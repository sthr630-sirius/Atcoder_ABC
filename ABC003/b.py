S = input()
T = input()
#print(S, T)

is_win = True
check_list = ["a", "t", "c", "o", "d", "e", "r"]

for check_s, check_t in zip(S, T):
    #print(check_s, check_t)
    if check_s == check_t:
        continue
    else:
        if check_s == "@" and check_t in check_list:
            continue
        elif check_t == "@" and check_s in check_list:
            continue

    is_win = False

if is_win:
    print("You can win")
else:
    print("You will lose")