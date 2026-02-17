from math import floor

n = int(input())
v = []
maior=0
for _ in range(n):
    s = input()
    v.append(s)
    maior = max(maior, len(s))


for s in v:
    if (len(s)==maior):
        print(s)
    else:
        r=""
        k = floor((maior-len(s))/2)
        r += '.'*k
        r+=s
        r+='.'*k
        print(r)
