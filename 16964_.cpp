#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> v[100001], order;

int n, idx = 1;

void search(int k)
{
    while (idx < n)
    {
        if (binary_search(v[k].begin(), v[k].end(), order[idx]))
            search(order[idx++]);
        else
            return;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b, c;
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
        order.push_back(c);
        sort(v[i].begin(), v[i].end());
    }
    if (order[0] == 1)
        search(1);
    cout << (idx >= n ? 1 : 0);
    return 0;
}