#include <iostream>

using namespace std;

int dp[2500][2500], n, d[2500];

int main(){
    string s;
    cin>>s;
    n=s.length();
    for(int i=0;i<n;i++){
        dp[i][i]=1;
        if(s[i]==s[i+1])dp[i][i+1]=1;
        for(int j=1;i-j>=0&&i+j<n;j++){
            if(dp[i-j+1][i+j-1]!=1) break;
            if(s[i-j]==s[i+j]) dp[i-j][i+j]=1;
        }
        for(int j=1;i-j>=0&&i+j+1<n;j++){
            if(dp[i-j+1][i+j]!=1) break;
            if(s[i-j]==s[i+j+1]) dp[i-j][i+j+1]=1;
        }
    }
    for(int i=0;i<n;i++){
        d[i]=2500;
        for(int j=0;j<=i;j++){
            if(dp[j][i]) d[i]=min(d[i],d[j-1]+1);
        }
    }
    cout<<d[n-1];
    return 0;
}