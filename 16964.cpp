#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v[100001];
    stack<int> s;
    int n, a, b, c, t, ans = 1;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    s.push(1);
    cin >> c;
    if (c != 1)
        ans = 0;
    for (int i = 1; i < n; i++)
    {
        cin >> c;
        if (!ans)
            continue;
        while (v[s.top()].empty())
        {
            s.pop();
        }
        t = s.top();
        vector<int>::iterator ite=find(v[t].begin(),v[t].end(),c);
        if(ite!=v[t].end()){
            s.push(c);
            v[t].erase(ite);
            v[c].erase(find(v[c].begin(),v[c].end(),t));
        }
        else ans=0;
    }
    cout << ans;
}