import sys


def dfs(n):
    global find
    if find:
        return
    if n == len(blank):
        for i in range(9):
            print(*a[i], sep="")
        find = True
        return
    r, c = blank[n]
    list = [i for i in range(1, 10)]
    for i in range(9):
        if a[r][i] in list:
            list.remove(a[r][i])
        if a[i][c] in list:
            list.remove(a[i][c])
    for i in range(3):
        for j in range(3):
            if a[(r // 3) * 3 + i][(c // 3) * 3 + j] in list:
                list.remove(a[(r // 3) * 3 + i][(c // 3) * 3 + j])
    for num in list:
        a[r][c] = num
        dfs(n + 1)
        a[r][c] = 0


a = [[*map(int, input())] for _ in range(9)]
blank = []
for i in range(9):
    for j in range(9):
        if not a[i][j]:
            blank.append((i, j))
find = False
dfs(0)
