A, B = map(int, input().split())
num = [1] * (B - A + 1)
for i in range(2, int(B ** 0.5) + 1):
    k = ((A - 1) // i ** 2 + 1) * i ** 2 - A
    while k < len(num):
        num[k] = 0
        k += i ** 2
print(sum(num))
