#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, board[20][20], siz=2, num=0, time=0, posx, posy, d[4][2]={{-1,0},{0,-1},{0,1},{1,0}};

bool bfs(){
    bool visit[20][20]={false,}, ate=false;
    int nx, ny, x, y, level, t=0, ansx=19, ansy=19;
    queue<pair<pair<int,int>, int>> q;
    visit[posx][posy]=true;
    q.push({{posx,posy},0});
    while(!q.empty()){
        x=q.front().first.first;
        y=q.front().first.second;
        level=q.front().second;
        if(t&&t<=level) break;
        q.pop();
        for(int i=0;i<4;i++){
            nx=x+d[i][0];
            ny=y+d[i][1];
            if(nx<0||ny<0||nx>=n||ny>=n||visit[nx][ny]) continue;
            visit[nx][ny]=true;
            if(board[nx][ny]<=siz){
                if(board[nx][ny]<siz&&board[nx][ny]>0){
                    ate=true;
                    t=level+1;
                    if(nx<=ansx){
                        if(nx==ansx) ansy=min(ansy,ny);
                        else{
                            ansx=nx;
                            ansy=ny;
                        }
                    }
                }
                if(!ate) q.push({{nx,ny},level+1});
            }
        }
    }
    time+=t;
    posx=ansx;
    posy=ansy;
    board[posx][posy]=0;
    num++;
    if(num==siz){
        num=0;
        siz++;
    }
    return ate;
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) {
            cin>>board[i][j];
            if(board[i][j]==9){
                posx=i;
                posy=j;
                board[i][j]=0;
            }
        }
    }
    while(bfs()){}
    cout<<time;
    return 0;
}