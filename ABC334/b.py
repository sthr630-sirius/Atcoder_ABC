a, m, l, r = map(int, input().split())
max_tree = (r-a)//m
min_tree = ((l-a)+m-1)//m
print(max_tree - min_tree + 1)