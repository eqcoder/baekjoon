A, B = input(), input()
a = len(A)
b = len(B)
dp = [[0] * (b + 1) for _ in range(a + 1)]
for i in range(1, a + 1):
    for j in range(1, b + 1):
        if A[i - 1] == B[j - 1]:
            dp[i][j] = dp[i - 1][j - 1] + 1
        else:
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
ans = ''
while a > 0 and b > 0:
    if dp[a][b - 1] + 1 == dp[a][b] and dp[a - 1][b] + 1 == dp[a][b]:
        ans = A[a - 1] + ans
        a -= 1
        b -= 1
    else:
        if dp[a - 1][b] > dp[a][b - 1]:
            a -= 1
        else:
            b -= 1
print(dp[-1][-1], '\n', ans)
