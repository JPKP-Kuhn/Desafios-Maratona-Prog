n = int(input())
 
numeros = list(map(int, input().split()))
 
for i in range(1, n+1):
    if i not in numeros:
        print(i)
        break
