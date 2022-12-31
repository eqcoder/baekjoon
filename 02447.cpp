#include <iostream>

using namespace std;

char s[2187][2187];

void star(int x, int y, int n) {
	if (n == 0) {
		s[x][y] = '*';
		return;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i != 1 || j != 1) star(x + i * n, y + j * n, n/3);
		}
	}
}

int main() {
	int n;
	cin >> n;
	star(0, 0, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << (s[i][j] == '*' ? '*' : ' ');
		}
		cout << "\n";
	}
	return 0;
}