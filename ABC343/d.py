n, t = map(int, input().split())
score = [0]*n
score_dict = {}

ans = 0
key = 0
score_dict[key] = n
ans += 1

#print(score)
#print(score_dict)
#print(ans)
#print("----")

for i in range(t):
    idx, s = map(int, input().split())
    idx -= 1

    del_key = score[idx]
    score[idx] += s
    key = score[idx]

    if key not in score_dict:
        score_dict[key] = 1
        score_dict[del_key] -=1
        if score_dict[del_key] == 0:
            del score_dict[del_key]
            ans -= 1
        ans += 1

    else:
        score_dict[key] += 1
        score_dict[del_key] -= 1
        if score_dict[del_key] == 0:
            del score_dict[del_key]
            ans -= 1

    print(ans)

    #print(score)
    #print(score_dict)
    #print(ans)
    #print("------")