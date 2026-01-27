from datetime import date

y = int(input("Ano: "))
m = int(input("Mês: "))
d = int(input("Dia: "))

s = date(y, m, d)
t = date.today()
print(s.strftime("%A"))
print(f"Foi a {(t-s).days} dias atrás")
