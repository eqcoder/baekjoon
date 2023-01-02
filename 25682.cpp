#include <iostream>
#include <algorithm>

using namespace std;

int n[2001][2001], ans=4000000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, K, m;
	char c;
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> c;
			n[i][j] = n[i - 1][j] + n[i][j - 1] - n[i - 1][j - 1] + (((i + j) % 2 && c == 'B') || ((i + j) % 2 == 0 && c == 'W'));
		}
	}
	for (int i = 0; i <= N - K; i++) {
		for (int j = 0; j <= M - K; j++) {
			m = n[i + K][j + K] - n[i][j + K] - n[i + K][j] + n[i][j];
			ans = min(ans, min(m, K * K - m));
		}
	}
	cout << ans;
	return 0;
}