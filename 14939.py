import sys

input = sys.stdin.readline
board = []
dx = [0, 1, -1, 0, 0]
dy = [0, 0, 0, 1, -1]
ans = 100


def push(x, y):
    for i in range(5):
        nx = x + dx[i]
        ny = y + dy[i]
        if nx < 10 and ny < 10 and nx >= 0 and ny >= 0:
            temp_board[nx][ny] = not temp_board[nx][ny]


for i in range(10):
    temp = list(input().strip())
    for j in range(10):
        if temp[j] == '#':
            temp[j] = False
        else:
            temp[j] = True
    board.append(temp)
for i in range(1 << 10):
    done = True
    but = 0
    temp_board = []
    for l in board:
        temp_board.append(l[:])
    for j in range(10):
        if i & (1 << j):
            push(0, j)
            but += 1
    for j in range(1, 10):
        for k in range(10):
            if temp_board[j - 1][k]:
                push(j, k)
                but += 1
    for j in range(10):
        if temp_board[9][j]:
            done = False
    if done:
        ans = min(ans, but)
print(ans)
