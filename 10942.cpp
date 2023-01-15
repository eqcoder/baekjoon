#include <iostream>

using namespace std;

bool dp[2001][2001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, s[2001], a, b;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; i + j - 1 <= n && i - j > 0 && s[i + j - 1] == s[i - j]; j++)
            dp[i - j][i + j - 1] = true;
        for (int j = 0; i + j <= n && i - j > 0 && s[i + j] == s[i - j]; j++)
            dp[i - j][i + j] = true;
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        cout << dp[a][b] << '\n';
    }
    return 0;
}