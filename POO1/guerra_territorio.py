n = int(input())
sec = list(map(int, input().split()))

soma = sum(sec)
pre=0

for i in range(n-1):
    pre += sec[i]
    if pre * 2 == soma:
        print(i+1)
        break

