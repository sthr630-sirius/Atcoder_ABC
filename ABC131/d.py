n = int(input())
task_info = [[0, 0] for _ in range(n)]
for i in range(n):
    a, b = map(int, input().split())
    task_info[i][0] = b
    task_info[i][1] = a
#print(task_info)
task_info.sort()
#print(task_info)
task_time = 0
is_task = True
for i in range(n):
    task_time += task_info[i][1]
    if task_time > task_info[i][0]:
        is_task = False
if is_task:
    print("Yes")
else:
    print("No")