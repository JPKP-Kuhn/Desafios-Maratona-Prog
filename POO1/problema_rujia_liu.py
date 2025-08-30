while True:
    try:
        n, m = map(int, input().split())
        vetor = list(map(int, input().split()))
        num = {}
        for i, val in enumerate(vetor):
            if val not in num:
                num[val] = []
            num[val].append(i+1)

        for _ in range(m):
            k, v = map(int, input().split())
            if v not in num or len(num[v]) < k:
                print(0)
            else:
                print(num[v][k-1])

    except EOFError:
        break
