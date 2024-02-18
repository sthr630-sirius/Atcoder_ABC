n = int(input())
difficulty = list(map(int, input().split()))
difficulty.sort()
half_index = n//2
print(difficulty[half_index] - difficulty[half_index-1])