#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int cnt[1001];
vector<int> v[1001], ans;
queue<int> q;

int main()
{
    int n, m, k, a, b, x;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> k >> a;
        for (int j = 0; j < k - 1; j++)
        {
            cin >> b;
            v[a].push_back(b);
            cnt[b]++;
            a = b;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!cnt[i])
            q.push(i);
    }
    while (!q.empty())
    {
        x = q.front();
        q.pop();
        ans.push_back(x);
        for (int i = 0; i < v[x].size(); i++)
        {
            if (--cnt[v[x][i]] == 0)
                q.push(v[x][i]);
        }
    }
    if (ans.size() != n)
        cout << 0;
    else
    {
        for (int i = 0; i < n; i++)
            cout << ans[i] << '\n';
    }
    return 0;
}