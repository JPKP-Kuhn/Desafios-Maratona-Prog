# Descobrir quantos dias faltam pro natal, dado um dia e um mes
# Ano é 2016 bissexto
ano = 366
natal = ano - (31 - 25)

jan = mar = mai = jul = ago = out = dez = 31
fev = 29
abr = jun = set = nov = 30

meses_ano = [jan, fev, mar, abr, mai, jun, jul, ago, set, out, nov, dez]

def dias_natal(mes, dia):
    if mes == 12 and dia == 25:
        return "E natal!"
    elif mes == 12 and dia == 24:
        return "E vespera de natal!"
    elif mes == 12 and dia > 25:
        return "Ja passou!"
    else:
        def calc_pro_natal(mes, dia):
            soma_dias = 0
            soma_meses_completos = 0

            meses = []
            for i in range(1, 13):
                meses.append(i)
                if i == mes:
                    break
            for j in range(len(meses)-1):
                soma_meses_completos += meses_ano[j]

            soma_dias = dia + soma_meses_completos
            res_natal = natal - soma_dias
            
            return res_natal

        return f"Faltam {calc_pro_natal(mes, dia)} dias para o natal!"


while True:
    try:
        mes, dia = map(int, input().split())
        print(dias_natal(mes, dia))
    except EOFError:
        break
