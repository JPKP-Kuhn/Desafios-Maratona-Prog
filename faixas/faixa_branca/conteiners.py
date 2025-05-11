container = input().split()
c_larg = int(container[0])
c_comp = int(container[1])
c_alt = int(container[2])

navio = input().split()
n_larg = int(navio[0])
n_comp = int(navio[1])
n_alt = int(navio[2])

c_por_larg = int(n_larg / c_larg)
c_por_comp = int(n_comp / c_comp)
c_por_alt = int(n_alt / c_alt)

print(c_por_larg * c_por_comp * c_por_alt)
