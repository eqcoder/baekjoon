import sys
from collections import Counter

input = sys.stdin.readline
N = int(input())
A = list(map(int, input().split()))
F = Counter(A)
ans = [-1] * N
temp = []
for i, a in enumerate(A):
    while temp and F[a] > F[A[temp[-1]]]:
        ans[temp.pop()] = a
    temp.append(i)
print(*ans)
