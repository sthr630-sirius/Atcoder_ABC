n = int(input())
A = list(map(int, input().split()))
query_2 = {}
for i, a in enumerate(A):
    query_2[i] = a

a = 0

q = int(input())

for _ in  range(q):
    query = input()
    
    if query[0] == "1":
        q_no, x = map(int, query.split())
        a = x
        query_2 = {}

    elif query[0] == "2":
        q_no, i, x = map(int, query.split())
        if i-1 in query_2:
            query_2[i-1] += x
        else:
            query_2[i-1] = x

    elif query[0] == "3":
        q_no, i = map(int, query.split())
        if i-1 in query_2:
            print(a+query_2[i-1])
        else:
            print(a)