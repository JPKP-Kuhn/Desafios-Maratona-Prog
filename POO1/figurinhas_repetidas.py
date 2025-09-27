n = int(input())
fig = []
rep = []
for i in range(n):
    x = int(input())
    if x not in fig:
        fig.append(x)
    else:
        rep.append(x)

print(len(fig))
print(len(rep))
