n = int(input())
num = list(map(int, input().split()))

maiorrep = 1
localrep = 1

for i in range(n-1):
    if num[i] == num[i+1]:
        localrep+=1 
    else:
        if localrep > maiorrep:
            maiorrep = localrep
        localrep=1

if localrep > maiorrep:
    maiorrep = localrep

print(maiorrep)

