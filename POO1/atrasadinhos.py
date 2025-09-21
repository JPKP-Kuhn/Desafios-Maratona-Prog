n, k = map(int, input().split())
a = list(map(int, input().split()))
c=0
for i in a:
    if i <= 0:
        c+=1
if c >= k:
    print("YES")
else:
    print("NO")
