w, h, x, y = map(int, input().split())
s = w*h/2
if x*2 == w and y*2 == h:
    print(f"{s} {1}")
else:
    print(f"{s} {0}")