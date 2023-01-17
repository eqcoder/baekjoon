#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> v[32001];
priority_queue<int,vector<int>,greater<int>> q;
int n, m, a, b, num[32001], x;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        v[a].push_back(b);
        num[b]++;
    }
    for(int i=1;i<=n;i++){
        if(!num[i]) q.push(i);
    }
    while(!q.empty()){
        x=q.top();
        q.pop();
        cout<<x<<" ";
        for(int i=0;i<v[x].size();i++){
            if(--num[v[x][i]]==0) q.push(v[x][i]);
        }
    }
    return 0;
}