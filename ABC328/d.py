s = input()
stock = []
for i in range(len(s)):
    stock.append(s[i])
    if len(s) >= 3 and s[i] == "C":
        if stock[-3:] == ["A", "B", "C"]:
            stock.pop()
            stock.pop()
            stock.pop()

stock = "".join(stock)
print(stock)

"""
first code
passed test case

stock_arr = []
judge_arr = []
for i in range(len(s)):
    #print(f"i:{i}")
    #print(s[i+1:])
    if len(judge_arr) < 3:
        judge_arr.append(s[i])
    elif len(judge_arr) == 3:
        if judge_arr == ["A", "B", "C"]:
            judge_arr = []
            if len(stock_arr) >= 2:
                judge_arr.append(stock_arr.pop(-2))
                judge_arr.append(stock_arr.pop())
            elif len(stock_arr) == 1:
                judge_arr.append(stock_arr.pop())
            judge_arr.append(s[i])
        else:
            stock_arr.append(judge_arr.pop(0))
            judge_arr.append(s[i])

    #print(judge_arr)
    #print(stock_arr)
    #print("----------------")

ans = stock_arr + judge_arr
if ans[-3:] == ["A", "B", "C"]:
    ans = ans[:-3]

ans = "".join(ans)
print(ans)
"""