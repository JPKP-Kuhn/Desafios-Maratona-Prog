n = input()
 
 
maior_repeticao = 1
qtd_repeticao_atual = 1
 
for i in range(1, len(n)):
	if n[i] == n[i-1]:
		qtd_repeticao_atual+=1
	else:
		if qtd_repeticao_atual > maior_repeticao:
			maior_repeticao = qtd_repeticao_atual
		qtd_repeticao_atual = 1
		
if qtd_repeticao_atual > maior_repeticao:
	maior_repeticao = qtd_repeticao_atual
			
print(maior_repeticao)
