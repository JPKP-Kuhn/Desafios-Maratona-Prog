test = int(input())

while test>0:
    y, x = map(int, input().split())
    mat = y * y - (y-1)

    if y == x:
        print(mat)
    elif y > x:
        if y % 2 == 1:
            d = mat - (y-x)
            print(d)
        else:
            d = mat + (y-x)
            print(d)
    elif x > y:
        matr = x * x - (x-1)
        if x % 2 == 1:
            d = matr + (x-y)
            print(d)
        else:
            d = matr - (x-y)
            print(d)

    test-=1
