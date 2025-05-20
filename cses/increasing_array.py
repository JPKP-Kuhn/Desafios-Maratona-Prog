s = int(input())
 
array = list(map(int, input().split()))
c = sorted(array)
a = 0
 
	
if c != array:
	for i in range(1, len(array)):
		if array[i-1] > array[i]:
			a+=abs(array[i-1] - array[i])
			array[i]+=abs(array[i-1] - array[i])
print(a)
