#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int n, parent[100];
vector<pair<double, double>> pos;
vector<pair<double, pair<int, int>>> v;

int find(int x)
{
    if (x == parent[x])
        return x;
    return parent[x] = find(parent[x]);
}

void Union(int x, int y)
{
    if (x > y)
        parent[x] = y;
    else
        parent[y] = x;
    return;
}

int main()
{
    int x, y;
    double a, b, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        cin >> a >> b;
        pos.push_back({ a, b });
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            v.push_back({ sqrt(pow(pos[i].first - pos[j].first, 2) + pow(pos[i].second - pos[j].second, 2)), { i, j } });
        }
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        x = find(v[i].second.first);
        y = find(v[i].second.second);
        if (x != y)
        {
            ans += v[i].first;
            Union(x, y);
        }
    }
    cout << ans;
    return 0;
}