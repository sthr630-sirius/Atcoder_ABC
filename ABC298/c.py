n = int(input())
Q = int(input())
cards = [[] for _ in range(200001)]
boxes = [[] for _ in range(n+1)]

for _ in range(Q):
    query = input()
    if(query[0] == "1"):
        q, i, j = map(int, query.split())
        cards[i].append(j)
        boxes[j].append(i)
    if(query[0] == "2"):
        q, i = map(int, query.split())
        boxes[i].sort()
        print(*boxes[i])
    if(query[0] == "3"):
        q, i = map(int, query.split())
        set_cards = set(cards[i])
        cards[i] = list(set_cards)
        cards[i].sort()
        print(*cards[i])