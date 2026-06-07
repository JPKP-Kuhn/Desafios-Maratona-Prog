i = 2
def solve(n):
    if (n==0):
        return 2
    
    soma = 2**(n-1)
    soma += solve(n-1)
    return soma
    

n = int(input())
con = solve(n)

print(con * con)

# 4    i=0  2
# 9    i=1  3 1
# 25   i=2  5 2
# 81   i=3  9 4
# 289  i=4  17 8
# 1089 i=5 33 16


