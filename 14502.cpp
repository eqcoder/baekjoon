#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int board[8][8], safe = 0, visit[8][8], n, m, d[4][2] = { { 1, 0 }, { 0, 1 }, { 0, -1 }, { -1, 0 } }, ans = 0;

int virus()
{
    queue<pair<int, int>> q;
    pair<int, int> pos;
    int x, y, s = safe;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 2)
                q.push({ i, j });
        }
    }
    while (!q.empty())
    {
        pos = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            x = pos.first + d[i][0];
            y = pos.second + d[i][1];
            if (x >= 0 && y >= 0 && x < n && y < m && !visit[x][y])
            {
                visit[x][y] = 1;
                if (board[x][y] == 0)
                {
                    s--;
                    q.push({ x, y });
                }
            }
        }
    }
    memset(visit, 0, sizeof(visit));
    return s - 3;
}

void wall(int cnt)
{
    if (cnt == 3)
    {
        ans = max(ans, virus());
        return;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 0)
            {
                board[i][j] = 1;
                wall(cnt + 1);
                board[i][j] = 0;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 0)
                safe++;
        }
    }
    wall(0);
    cout << ans;
}