#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int main()
{
    int g, p, ans=0;
    cin >> g >> p;
    for (int i = 1; i <= g; i++)
        v.push_back(i);
    for (int i = 0; i < p; i++)
    {
        cin >> g;
        vector<int>::iterator it = upper_bound(v.begin(), v.end(), g);
        if(it==v.begin()) break;
        v.erase(it-1);
        ans++;
    }
    cout<<ans;
    return 0;
}