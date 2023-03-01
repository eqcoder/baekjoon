#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, k, a, b, ans;
vector<pair<int, int>> v;
vector<int> num, line;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
	ans=n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        v.push_back({ a, b });
    }
    sort(v.begin(), v.end());
    line.push_back(v[0].second);
    num.push_back(0);
    for (int i = 1; i < n; i++)
    {
        k = lower_bound(line.begin(), line.end(), v[i].second) - line.begin();
        if (k == line.size())
            line.push_back(v[i].second);
        line[k] = v[i].second;
        num.push_back(k);
    }
    k = line.size() - 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (num[i] == k)
        {
			ans--;
            v[i].first = -1;
            k--;
        }
    }
    cout << ans<<'\n';
    for (int i = 0; i < n; i++)
    {
        if (v[i].first != -1)
            cout << v[i].first << '\n';
    }
    return 0;
}