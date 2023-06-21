def trapezoidal_rule(f, a, b, n):
    """
    Calcula a integral de f(x) usando a regra do trapézio.
    
    Argumentos:
    f -- função a ser integrada
    a -- limite inferior de integração
    b -- limite superior de integração
    n -- número de subintervalos (quanto maior, maior será a precisão)
    
    Retorna:
    O valor aproximado da integral definida de f(x) no intervalo [a, b]
    """
    h = (b - a) / n
    result = 0.5 * (f(a) + f(b))

    for i in range(1, n):
        x = a + i * h
        result += f(x)

    result *= h

    return result

# Exemplo de função a ser integrada: f(x) = x^2
def function(x):
    return x**2

# Limites de integração
a = 0
b = 1

# Número de subintervalos
n = 100

# Chamada da função da regra do trapézio
integral = trapezoidal_rule(function, a, b, n)

# Exibindo o resultado
print("O valor aproximado da integral é:", integral)

