n = int(input())

magic_card = []
ans = []

for i in range(n):
    a, c = map(int, input().split())
    magic_card.append([a, c, i+1])

magic_card.sort(reverse=True)

a = magic_card[0][0]
c = magic_card[0][1]
no = magic_card[0][2]

ans.append([no, a, c])
min_cost = c

for i in range(1, n):
    a = magic_card[i][0]
    c = magic_card[i][1]
    no = magic_card[i][2]
    if min_cost > c:
        ans.append([no, a, c])
        min_cost = c

ans.sort()

print(len(ans))
for i in range(len(ans)):
    print(ans[i][0], end=" ")