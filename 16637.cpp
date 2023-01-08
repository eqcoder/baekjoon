#include <iostream>

using namespace std;

int n, k, ans = INT32_MIN;
char str[22];

void calc(int k, int result)
{
    if (k >= n)
    {
        ans = max(ans, result);
        return;
    }
    int temp = str[k] - 48;
    int paren = temp;
    if(k!=n-1){
    if (str[k + 1] == '+')
        paren += (str[k + 2] - 48);
    else if (str[k + 1] == '-')
        paren -= (str[k + 2] - 48);
    else
        paren *= (str[k + 2] - 48);
    }
    if (str[k - 1] == '+')
    {
        calc(k + 2, result + temp);
        calc(k + 4, result + paren);
    }
    else if (str[k - 1] == '-')
    {
        calc(k + 2, result - temp);
        calc(k + 4, result - paren);
    }
    else
    {
        calc(k + 2, result * temp);
        calc(k + 4, result * paren);
    }
}

int main()
{
    cin >> n;
    cin >> str;
    calc(2, str[0] - 48);
    cout << ans;
    return 0;
}