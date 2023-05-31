# by Leon Augusto

def f(x): # function exemple 1
	return 2 * x + 5

# def f(x): # function exemple 2
# 	return 4 * x**2 + 3 * x

# def f(x): # function exemple 3
# 	return 2 * x**3 + 4 * x**2

# def f(x): # function exemple 4
# 	return x**3 - 10*x**2 + 5


a = int(input('Margem esquerda do intervalo: '))
b = int(input('Margem direita do intervalo: '))

n = int(input('Máximo de interações: '))

header = ['Iteração', 'a', 'b', 'k', 'f() no Ponto k']

print('-' * 108)
print('{:^10} |{:^20} |{:^20} |{:^20} |{:^30}'.format(*header))
print('-' * 108)


for i in range(1, n+1):
	k=(a+b)/2

	datas = [i, a, b, k, f(k)]
	
	print('{:^10} |{:>20} |{:>20} |{:>20} |{:>30}'.format(*datas))

	if f(k)==0:
		break

	if f(a)*f(k) < 0:
		b=k
	else:
		a=k


print('RESULTADO FINAL')

print(f'Iteração do Valor Encotrado: {i}ª')
print(f'Intervalo Oferecido: [{a}, {b}]')
print(f'Valor da Solução Procurada: {k}')
print(f'Valor de f() no Ponto k (espera-se próximo de zero): {k}')

