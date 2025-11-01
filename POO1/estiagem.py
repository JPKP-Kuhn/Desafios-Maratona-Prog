cidade=1
while True:
    n = int(input())
    if n==0:
        break
    soma, div =0,0
    pes_con = []
    for _ in range(n):
        x, y = map(int, input().split())
        soma+=y
        div+=x
        pes_con.append((y//x, x))
    media=soma/div

    pes_con = sorted(pes_con)
    print(f"Cidade# {cidade}:")
    cidade+=1
    for i in pes_con:
        x, y = i
        print(f"{y}-{x}", end=' ')
    print()
    print(f"Consumo medio: {media:.2f} m3.")
    print()
