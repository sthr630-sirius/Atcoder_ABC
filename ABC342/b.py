n = int(input())
line_info = list(map(int, input().split()))
line_dict = {}
for i in range(n):
    line_dict[line_info[i]] = i+1
#print(line_dict)

q = int(input())
for i in range(q):
    a, b = map(int, input().split())
    print(line_info[min(line_dict[a], line_dict[b])-1])
