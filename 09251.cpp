#include <iostream>
#include <cstring>

using namespace std;

char board[2001][2001];

int main() {
	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		cin >> board[i];
	}
	cout << board[0];
	return 0;
}