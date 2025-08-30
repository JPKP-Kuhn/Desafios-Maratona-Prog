while True:
    n, m = map(int, input().split())
    if n== 0 and m == 0:
        break
    troco = m - n
    c=0
    mior = False
    v = [2, 5, 10, 20, 50, 100]
    for i in range(len(v)):
        for j in range(i+1, len(v)):
            if v[i] + v[j] == troco:
                mior = True
                break
            
    if not mior:
        print('impossible')
    else:
        print('possible')
