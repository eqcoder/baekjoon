#include <iostream>

using namespace std;

int main()
{
    int dp[2501]={0,}, n;
    char s[2502];
    cin >> s+1;
    for (n = 1; s[n]; n++)
        dp[n] = n;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; i + j - 1 < n && i - j > 0 && s[i + j - 1] == s[i - j]; j++)
            dp[i + j - 1] = min(dp[i + j - 1], dp[i - j - 1] + 1);
        for (int j = 0; i + j < n && i - j > 0 && s[i + j] == s[i - j]; j++)
            dp[i + j] = min(dp[i + j], dp[i - j - 1] + 1);
    }
    cout << dp[n-1];
    return 0;
}