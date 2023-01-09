#include <algorithm>
#include <iostream>

using namespace std;

int n, visit[50][50], d[6][2] = { { -1, 0 }, { -1, 1 }, { 0, -1 }, { 1, -1 }, { 1, 0 }, { 0, 1 } }, ans = 0;
char board[51][51];

void dfs(int x, int y, int color)
{
    int nx, ny;
    visit[x][y] = color;
    ans = max(ans, 1);
    for (int i = 0; i < 6; i++)
    {
        nx = x + d[i][0];
        ny = y + d[i][1];
        if (nx >= 0 && ny >= 0 && nx < n && ny < n)
        {
            if (board[nx][ny] == 'X')
            {
                if (visit[nx][ny] == color)
                {
                    cout << 3;
                    exit(0);
                }
                else if (!visit[nx][ny])
                {
                    ans = 2;
                    dfs(nx, ny, (color == 2 ? 1 : 2));
                }
            }
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> board[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 'X' && !visit[i][j])
                dfs(i, j, 1);
        }
    }
    cout << ans;
    return 0;
}