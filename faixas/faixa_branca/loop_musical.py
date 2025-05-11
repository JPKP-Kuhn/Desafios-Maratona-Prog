n = int(input())

while n > 0:
    l = list(map(int, input().split()))
    p = 0

    t = len(l)

    for i in range(t):
        anterior = (i - 1) % t
        posterior = (i + 1) % t

        # Pico ocorre quando é maior que os vizinhos ou menor, vale
        if (l[i] > l[anterior] and l[i] > l[posterior]) or (l[i] < l[anterior] and l[i] < l[posterior]):
            p+=1

    print(p)


    n = int(input())
