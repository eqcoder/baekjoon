#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct pos
{
    int x, y, num, dir;
};

int w, h, mirror = 10000, d[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } }, visit[101][101], posx, posy;
char board[101][101];

void bfs()
{
    int x, y, num, nx, ny, dir, new_num;
    queue<pos> q;
    q.push({ posx, posy, -1, -1 });
    visit[posx][posy] = -1;
    while (!q.empty())
    {
        x = q.front().x;
        y = q.front().y;
        num = q.front().num;
        dir = q.front().dir;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            new_num = num + (dir != i);
            nx = x + d[i][0];
            ny = y + d[i][1];
            if (nx < 0 || ny < 0 || nx >= h || ny >= w || visit[nx][ny] < new_num || board[nx][ny] == '*' || new_num >= mirror)
                continue;
            visit[nx][ny] = min(visit[nx][ny], new_num);
            if (board[nx][ny] == 'C')
                mirror = min(mirror, new_num);
            else
                q.push({ nx, ny, new_num, i });
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> w >> h;
    for (int i = 0; i < h; i++)
        cin >> board[i];
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            visit[i][j] = 10000;
            if (board[i][j] == 'C')
            {
                posx = i;
                posy = j;
            }
        }
    }
    bfs();
    cout << mirror;
    return 0;
}