human_num = int(input())
human_list = []
rank = 1
flag = 0
for i in range(human_num):
    cm_kg = list(map(int, input().split()))
    human_list.append(cm_kg)
for i in range(len(human_list)):
    rank = 1
    for j in range(len(human_list)):
        if i == j:
            continue
        if human_list[i][0] < human_list[j][0]:
            flag = 1
            if human_list[i][1] < human_list[j][1]:
                flag = 1
                if flag == 1:
                    rank = rank + 1
    print(rank)