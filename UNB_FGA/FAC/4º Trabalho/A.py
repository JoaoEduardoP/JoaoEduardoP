def zeta(s):
    epsilon = 1e-6
    zeta_atual = 0.0
    n = 1
    
    while True:
        termo = 1.0 / (n ** s)
        zeta_atual += termo
        
        if termo <= epsilon:
            break
        
        n += 1
    
    # Correção: aproxima a soma de n+1 até infinito por uma integral
    # sum_{k=n+1}^inf 1/k^s ≈ n^(1-s) / (s-1)
    correcao = (n ** (1 - s)) / (s - 1)
    zeta_atual += correcao
    
    return zeta_atual

s = int(input())
resultado = zeta(s)
print(f"{resultado:.4f}")