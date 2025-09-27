n = int(input())
l = list(map(int, input().split()))

res = l[0]
maxRes = l[0]

for i in range(1, n):
    maxRes = max(l[i], maxRes + l[i])
    res = max(res, maxRes)

print(res)
