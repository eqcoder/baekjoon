#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

int n, m, map[100][100], air_area[100][100], d[4][2] = { { -1, 0 }, { 0, -1 }, { 0, 1 }, { 1, 0 } }, time = 0;
vector<pair<int, int>> cheese;
stack<int> melted;

void FindOutside(int x, int y)
{
    int nx, ny;
    queue<pair<int, int>> q;
    q.push({ x, y });
    air_area[x][y] = 1;
    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            nx = x + d[i][0];
            ny = y + d[i][1];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || air_area[nx][ny] || map[nx][ny])
                continue;
            air_area[nx][ny] = 1;
            q.push({ nx, ny });
        }
    }
}

void Ismelt(int k)
{
    int nx, ny, air = 0;
    for (int i = 0; i < 4; i++)
    {
        nx = cheese[k].first + d[i][0];
        ny = cheese[k].second + d[i][1];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
            continue;
        air += air_area[nx][ny];
    }
    if (air >= 2)
        melted.push(k);
}

void DoMelt()
{
    int x, y, nx, ny;
    while (!melted.empty())
    {
        x = cheese[melted.top()].first;
        y = cheese[melted.top()].second;
        cheese.erase(cheese.begin() + melted.top());
        air_area[x][y] = 1;
        melted.pop();
        for (int i = 0; i < 4; i++)
        {
            nx = x + d[i][0];
            ny = y + d[i][1];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (!air_area[nx][ny] && !map[nx][ny])
                FindOutside(nx, ny);
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
            cin >> map[i][j];
            if (map[i][j] == 1)
                cheese.push_back({ i, j });
        }
    }
    FindOutside(0, 0);
    while (!cheese.empty())
    {
        for (int k = 0; k < cheese.size(); k++)
            Ismelt(k);
        DoMelt();
        time++;
    }
    cout << time;
    return 0;
}
