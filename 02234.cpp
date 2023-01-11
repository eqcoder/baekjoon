#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, d[4][2] = { { 0, -1 }, { -1, 0 }, { 0, 1 }, { 1, 0 } }, visit[51][51], map[51][51], wall[4] = { 1, 2, 4, 8 }, max_room = 0, room_num = 0, new_room = 0;
vector<int> room_size;

void bfs(int x, int y)
{
    int nx, ny, room = 1;
    queue<pair<int, int>> q;
    visit[x][y] = -1;
    q.push({ x, y });
    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            nx = x + d[i][0];
            ny = y + d[i][1];
            if (map[x][y] & wall[i] || visit[nx][ny])
                continue;
            visit[nx][ny] = -1;
            q.push({ nx, ny });
            room++;
        }
    }
    room_num++;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visit[i][j] == -1)
                visit[i][j] = room_num;
        }
    }
    room_size.push_back(room);
    max_room = max(max_room, room);
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    room_size.push_back(0);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> map[i][j];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visit[i][j])
                bfs(i, j);
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visit[i][j] != visit[i][j + 1])
                new_room = max(new_room, room_size[visit[i][j]] + room_size[visit[i][j + 1]]);
            if (visit[i][j] != visit[i + 1][j])
                new_room = max(new_room, room_size[visit[i][j]] + room_size[visit[i + 1][j]]);
        }
    }
    cout << room_num << "\n"
         << max_room << "\n"
         << new_room << "\n";
    return 0;
}