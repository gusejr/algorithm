number = int(input())
for i in range(0, number):
    a = list(input())
    h = 0
    sum1 = 0
    for j in range(len(a)):
        if a[j] == 'O':
            h = h + 1
            sum1 = sum1 + h
        elif a[j] == 'X':
            h = 0
    print(sum1)