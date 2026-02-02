a = input()
if '=' in a:
    a = a.replace('=', '==', 1)
a = eval(a)

if a:
    print('Right')
else:
    print('Wrong')
