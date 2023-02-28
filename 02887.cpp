#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int idx, parent[100000];
vector<vector<int>> v, dis;
bool comp(vector<int> a, vector<int> b)
{
    return a[idx] < b[idx];
}

int find(int x)
{
    if (x == parent[x])
        return x;
    else
        return parent[x] = find(parent[x]);
}

int main()
{
    cin.tie(null);
    ios_base::sync_with_stdio(false);
    int n, cost = 0, x, y, z;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        cin >> x >> y >> z;
        v.push_back({ x, y, z, i });
    }
    for (idx = 0; idx < 3; idx++)
    {
        sort(v.begin(), v.end(), comp);
        for (int i = 0; i < n - 1; i++)
        {
            dis.push_back({ v[i + 1][idx] - v[i][idx], v[i + 1][3], v[i][3] });
        }
    }
    sort(dis.begin(), dis.end());
    for (int i = 0; i < dis.size(); i++)
    {
        x = find(dis[i][1]);
        y = find(dis[i][2]);
        if (x != y)
        {
            cost += dis[i][0];
            parent[y] = x;
        }
    }
    cout << cost;
    return 0;
}