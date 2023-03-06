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
    if a==b:
        return False
    if a < b:
        parent[b] = a
    else:
        parent[a] = b
    return True
def kruscal():
    cost=0
    for a,b,c in paths:
        if union(a,b):
            cost+=c
    return cost


N, M = map(int, input().split())
parent = [i for i in range(N + 1)]
paths = [tuple(map(int, input().split())) for _ in range(M)]
paths.sort(key=lambda x: x[2])
print(kruscal())
