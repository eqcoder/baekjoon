#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int order[100001];
bool visit[100001];

bool comp(const int &a, const int &b)
{
    return order[a] < order[b];
}

int main()
{
    vector<int> v[100001];
    queue<int> q;
    int n, a, b, c, k, idx = 1;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> c;
        order[c] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        sort(v[i].begin(), v[i].end(), comp);
    }
    q.push(1);
    visit[1] = true;
    while (!q.empty())
    {
        k = q.front();
        q.pop();
        for (vector<int>::iterator i = v[k].begin(); i != v[k].end(); i++)
        {
            if (!visit[*i])
            {
                visit[*i] = true;
                q.push(*i);
            }
        }
        if (order[k] != idx++)
            break;
    }
    cout << (idx > n ? 1 : 0);
}