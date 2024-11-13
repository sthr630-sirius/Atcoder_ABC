import numpy as np

n = int(input())

carpets = [0, 0, 0, 0, 0, 0, 0]
carpets[0] = np.array([["#"]])


for i in range(1, n+1):
    carpets[i] = np.full((3**i, 3**i), "+")

for i in range(1, n+1):
    for j in range(len(carpets[i])):
        carpets[i][j] = np.concatenate([carpets[i-1][j%3**(i-1)], carpets[i-1][j%3**(i-1)], carpets[i-1][j%3**(i-1)]])

    for u in range(3**(i-1), 2*3**(i-1)):
        for v in range(3**(i-1), 2*3**(i-1)):
            carpets[i][u][v] = "."

for row in carpets[n]:
    print(*row, sep='')