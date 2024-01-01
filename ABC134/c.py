n = int(input())
a = [int(input()) for _ in range(n)]
sorted_a = sorted(a)
max_a = sorted_a[-1]
second_a = sorted_a[-2]
for target in a:
    if target == max_a:
        print(second_a)
    else:
        print(max_a)
