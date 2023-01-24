#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int cnt[32001];
vector<int> v[32001];
queue<int> q;

int main(){
    int n, m, a, b, x;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        v[a].push_back(b);
        cnt[b]++;
    }
    for(int i=1;i<=n;i++){
        if(!cnt[i]) q.push(i);
    }
    while(!q.empty()){
        x=q.front();
        q.pop();
        cout<<x<<" ";
        for(int i=0;i<v[x].size();i++){
            if(--cnt[v[x][i]]==0) q.push(v[x][i]);
        }
    }
    return 0;
}