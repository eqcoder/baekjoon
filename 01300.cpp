#include <iostream>

using namespace std;

int n, k, sum = 0, i = 1;

int BinarySearch(int left, int right)
{
    if (left > right)
        return left;
    int mid = (left + right) / 2, cnt = 0;
    for (int i = 1; i <= n; i++)
        cnt += (n > mid / i ? mid / i : n);
    if (cnt < k)
        return BinarySearch(mid + 1, right);
    else
        return BinarySearch(left, mid - 1);
}

int main()
{
    cin >> n >> k;
    cout << BinarySearch(1, k);
    return 0;
}