import math

def inv_gamma(z):
    GAMMA_CONST = 0.5772156649015329
    epsilon = 1e-6
    
    produto = 1.0
    k = 1
    
    # valor inicial (antes de multiplicar qualquer termo do produtório)
    valor_anterior = z * math.exp(GAMMA_CONST * z) * produto
    
    while True:
        fator = (1.0 + z / k) * math.exp(-z / k)
        produto *= fator
        
        valor_atual = z * math.exp(GAMMA_CONST * z) * produto
        
        if abs(valor_atual - valor_anterior) <= epsilon:
            break
        
        valor_anterior = valor_atual
        k += 1
    
    return valor_atual

# Entrada e saída
z = float(input())
resultado = inv_gamma(z)
print(f"{resultado:.3f}")