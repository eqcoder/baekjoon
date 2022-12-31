#include <iostream>

using namespace std;

char s[6561][6561];

void star(int x, int y, int size){
	int n = size / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1) continue;
			if (n == 0) s[x + i][y + j] = '*';
			else star(x + j * n, y + j * n, n / 3);
		}
	}
}

int main() {
	int n;
	cin >> n;
	star(0, 0, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << s[i][j];
		}
		cout << '\n';
	}
	return 0;
}