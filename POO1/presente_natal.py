while True:
    n = int(input())
    if n == 0:
        break
    
    p = list(map(int, input().split()))
    caro = 0
    barato = 1000000
    for i in range(len(p)):
        par = p[i] + p[len(p)-i-1]
        if par > caro:
            caro = par
        if par < barato:
            barato = par
            
    print(caro, barato)
