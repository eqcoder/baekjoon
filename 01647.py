import sys

sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline


def find(x):
    if parent[x] == x:
        return x
    parent[x] = find(parent[x])
    return parent[x]


def union(a, b):
    a = find(a)
    b = find(b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b


N, M = map(int, input().split())
parent = [i for i in range(N + 1)]
paths = []
result = 0
value = 0
for _ in range(M):
    a, b, c = map(int, input().split())
    paths.append((a, b, c))
paths.sort(key=lambda x: x[2])
for path in paths:
    a, b, c = path
    if (find(a) != find(b)):
        union(a, b)
        result += c
        if value <= c:
            value = c
print(result - value)
