import numpy as np

matrix_size = 4
g = np.full((matrix_size, matrix_size), ".")
g_rot = g.copy()

for i in range(matrix_size):
    g[i] = list(input().split())

for i in range(matrix_size):
    g_rot[:, matrix_size-(i+1)] = g[i, :]

g = g_rot.copy()

for i in range(matrix_size):
    g_rot[:, matrix_size-(i+1)] = g[i, :]

for row in g_rot:
    print(*row)