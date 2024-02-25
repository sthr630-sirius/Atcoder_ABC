n = int(input())
s = list(input())
q = int(input())
exchange_dict = {"a":"a", "b":"b", "c":"c", "d":"d", "e":"e", "f":"f", "g":"g", "h":"h", "i":"i", "j":"j", "k":"k", "l":"l", "m":"m", "n":"n", "o":"o", "p":"p", "q":"q", "r":"r", "s":"s", "t":"t", "u":"u", "v":"v", "w":"w", "x":"x", "y":"y", "z":"z"}
query = [["", ""] for _ in range(q)]
#print(exchange_dict)

for i in range(q):
    c, d =input().split()
    query[i] = [c, d]

#print(query)

for org_key, org_value in zip(exchange_dict.keys(), exchange_dict.values()):
    #print(org_key)
    key = org_key
    value = org_value
    for i in range(q):
        #if org_key == "r":
           #print(query[i][0], query[i][1])
           #print(key)
        if key == query[i][0]:
            #print(i)
            key = query[i][1]
            #key == query[i][0]
    exchange_dict[org_key] = key

#print(exchange_dict)

for i in range(len(s)):
    s[i] = exchange_dict[s[i]]

ans = "".join(s)
print(ans)

