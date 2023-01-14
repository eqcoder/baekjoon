#include <iostream>
#define mod 1000000000;

using namespace std;

int dp[10][10][10], ans[10][10][10];

int main()
{
    int n, sum = 0;
    cin >> n;
    for (int i = 1; i < 10; i++)
        dp[i][i][i] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = j; k < 10; k++)
            {
                if (j > 0)
                    ans[j - 1][k][j - 1] = (ans[j - 1][k][j - 1] + dp[j][k][j]) % mod;
                if (k < 9)
                    ans[j][k + 1][k + 1] = (ans[j][k + 1][k + 1] + dp[j][k][k]) % mod;
                for (int l = j; l <= k; l++)
                {
                    if (l > j)
                        ans[j][k][l] = (ans[j][k][l] + dp[j][k][l - 1]) % mod;
                    if (l < k)
                        ans[j][k][l] = (ans[j][k][l] + dp[j][k][l + 1]) % mod;
                }
            }
        }
        if (i == n)
            break;
        for (int j = 0; j < 10; j++)
        {
            for (int k = j; k < 10; k++)
            {
                for (int l = j; l <= k; l++)
                {
                    dp[j][k][l] = ans[j][k][l];
                    ans[j][k][l] = 0;
                }
            }
        }
    }
    for (int i = 0; i < 10; i++)
        sum = (sum + ans[0][9][i]) % mod;
    cout << sum;
    return 0;
}