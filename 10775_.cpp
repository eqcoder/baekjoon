#include <iostream>

using namespace std;

int gate[100001], g, p;

int find(int x)
{
    if (gate[x] == x)
        return x;
    return gate[x] = find(gate[x]);
}

void Union(int x, int y)
{
    x = find(x);
    y = find(y);
    gate[x] = y;
    return;
}

int main()
{
    int k, ans = 0;
    cin >> g >> p;
    for (int i = 0; i <= g; i++)
        gate[i] = i;
    for (int i = 0; i < p; i++)
    {
        cin >> g;
        k = find(g);
        if (!k)
            break;
        Union(k, k - 1);
        ans++;
    }
    cout << ans;
    return 0;
}