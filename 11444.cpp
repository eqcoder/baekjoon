#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, map[100][100], visit[100][100], d[4][2] = { { -1, 0 }, { 0, -1 }, { 0, 1 }, { 1, 0 } };
vector<int>

    void outside(int x, int y)
{
    int nx, ny;
    queue<pair<int, int>> q;
    q.push({ x, y });
    visit[x][y] = 1;
    while (q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            nx = x + d[i][0];
            ny = y + d[i][1];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || visit[nx][ny])
                continue;
            visit[nx][ny] = 1;
            q.push({ nx, ny });
        }
    }
}

void melt(int x, int y)
{
    int nx, ny, air;
    queue<pair<int, int>> q;
    q.push({ x, y });
    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        air = 0;
        for (int i = 0; i < 4; i++)
        {
            nx = x + d[i][0];
            ny = y + d[i][1];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || visit[nx][ny])
                continue;
            visit[nx][ny] = 1;
            q.push({ nx, ny });
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 1)
        }
        outside(0, 0);
        while (1)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (map[i][j] == 1)
                    {
                        melt(i, j);
                    }
                }
            }
        }
    }