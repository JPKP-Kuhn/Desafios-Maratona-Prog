l = int(input())

c=1
t=0
if l == 2 or l ==3:
    print(4)
else:
    while(l>=2):
        if (t %2==0):
            c*=4
        l/=2
    print(c)
