a, b, c = map(int , input().split())

v = [a, b, c]
v.sort()

if (a < b+c and b < a+c and c < b+a):
    if (v[2]**2 < v[0]**2 + v[1]**2):
        print("a")
    elif (v[0]**2 + v[1]**2 == v[2]**2):
        print("r")
    elif (v[2]**2 > v[0]**2 + v[1]**2):
        print("o")
else:
    print('n')
