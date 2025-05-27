n = int(input())
 
a = []
 
for i in range(1, n+1):
	if i % 2 == 0:
		a.append(i)
		
for i in range(1, n+1):
	if i % 2 == 1:
		a.append(i)
		
if n == 2 or n == 3:
	print("NO SOLUTION")
else:
	for i in a:
		print(i, end=' ')
	print()
