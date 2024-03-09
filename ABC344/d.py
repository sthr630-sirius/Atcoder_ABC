t = list(input())
t = ["*"] + t
n = int(input())
inf = 999
inf_1 = 998
dp = [[inf]*(len(t)) for _ in range(n+1)]
#for i in range(len(t)+1):
#    dp[0][i] = inf_1

for i in range(n+1):
    dp[i][0] = 0

for i in range(1, n+1):
    i_data = list(input().split())
    #print(i_data)
    m = int(i_data.pop(0))
    for s in i_data:
        #print(s)
        for j in range(1, len(t)):
            if j-len(s)>=0 and dp[i-1][j-len(s)] != inf and t[j-len(s)+1:j+1] == list(s):
                #print(f"ans:{s}")
                #print(dp[i-1][j-len(s)]+1)
                #print(dp[i-1][j])
                dp[i][j] = min(dp[i-1][j-len(s)]+1, dp[i-1][j])

            dp[i][j] = min(dp[i][j], dp[i-1][j])

            #for dpi in dp:
            #    print(dpi)
            #print("--------------")
if dp[n][len(t)-1] == inf:
    print(-1)
else:
    print(dp[n][len(t)-1])