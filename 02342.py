def power(loc, move):
    if loc == move:
        return 1
    elif loc == 0:
        return 2
    elif abs(loc - move) % 2:
        return 3
    else:
        return 4


a = list(map(int, input().split()))
n = len(a)
list = [[[1000000] * 5 for _ in range(5)] for _ in range(n + 1)]
list[0][0][0] = 0
for i, pos in enumerate(a):
    for left in range(5):
        for right in range(5):
            list[i + 1][pos][right] = min(list[i + 1][pos][right], list[i][left][right] + power(left, pos))
            list[i + 1][left][pos] = min(list[i + 1][left][pos], list[i][left][right] + power(right, pos))
result = 1000000
for i in range(5):
    for j in range(5):
        result = min(result, list[n - 1][i][j])
print(result)
