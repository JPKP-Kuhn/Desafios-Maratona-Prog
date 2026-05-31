def polygonArea(pontos):
    area=0

    n = len(pontos)
    j = n-1

    for i in range(n):
        area += pontos[j][0] * pontos[i][1] - pontos[j][1] * pontos[i][0]
        j=i

    return abs(area)

n = int(input())
pontos = []
for _ in range(n):
    x, y = map(int, input().split())
    a = [x, y]
    pontos.append(a)

area = polygonArea(pontos)
print(area)
