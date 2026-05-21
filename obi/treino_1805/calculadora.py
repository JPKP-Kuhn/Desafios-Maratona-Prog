n = int(input())

res = 1.0
for _ in range(n):
    num, op = input().split()
    num = int(num)
    if op == '*':
        res *= num
    elif op == '/':
        res /= num
print(round(res))

