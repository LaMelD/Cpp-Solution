def FIBO(n):
    fibo = [0, 1]
    for i in range(n - 1):
        fibo.append(fibo[i] + fibo[i + 1])
    return fibo[n]

n = int(input(''))

print(FIBO(n))