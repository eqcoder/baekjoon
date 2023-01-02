#include <iostream>

using namespace std;

long long s[1000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, sum=0, k;
	long long cnt = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> k;
		sum += k;
		sum %= M;
		s[sum]++;
	}
	for (int i = 0; i < M; i++) {
		cnt += ((s[i] * (s[i]-1)) / 2);
	}
	cnt += s[0];
	cout << cnt;
	return 0;
}