number1, number2 = map(str, input().split())
new_number1 = ''.join(list(reversed(number1)))
new_number2 = ''.join(list(reversed(number2)))
print(max(int(new_number1), int(new_number2)))