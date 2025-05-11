def notas(valor):
    nota100 = int(valor / 100)
    valor %=  100

    nota50 = int(valor / 50)
    valor %=  50

    nota20 = int(valor / 20)
    valor %=  20

    nota10 = int(valor / 10)
    valor %= 10

    nota5 = int(valor / 5)
    valor %= 5

    nota2 = int(valor / 2)
    valor %= 2

    print(f"""NOTAS:
{nota100} nota(s) de R$ 100.00
{nota50} nota(s) de R$ 50.00
{nota20} nota(s) de R$ 20.00
{nota10} nota(s) de R$ 10.00
{nota5} nota(s) de R$ 5.00
{nota2} nota(s) de R$ 2.00""")

    valor *= 100

    moeda1 = int(valor / 100)
    valor %= 100

    moeda50 = int(valor / 50)
    valor %= 50

    moeda25 = int(valor / 25)
    valor %= 25

    moeda10 = int(valor / 10)
    valor %= 10

    moeda5 = int(valor / 5)
    valor %= 5

    moeda01 = int(valor / 1)
    valor %= 1

    print(f"""MOEDAS:
{moeda1} moeda(s) de R$ 1.00
{moeda50} moeda(s) de R$ 0.50
{moeda25} moeda(s) de R$ 0.25
{moeda10} moeda(s) de R$ 0.10
{moeda5} moeda(s) de R$ 0.05
{moeda01} moeda(s) de R$ 0.01""")


valor = float(input())
notas(valor)
