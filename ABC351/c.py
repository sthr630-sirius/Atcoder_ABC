n = int(input())
a = list(map(int, input().split()))

box = []

for i in range(n):
    box.append(a[i])
    length = len(box)
    while length > 1:
        if box[-1] == box[-2]:
            box[-2] += 1
            length -= 1
            box.pop()
        else:
            break

print(len(box))