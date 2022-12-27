#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

char s[6562][6562];

void star(int x, int y, int size){
	int n = size / 3;
	if (n==1) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i != 1 || j != 1) s[x + i][y + j] = '*';
			}
		}
	}
	else {
		star(x, y, n);
		star(x, y+n, n);
		star(x, y+2*n, n);
		star(x+n, y, n);
		star(x+2*n, y, n);
		star(x+n, y+2*n, n);
		star(x+2*n, y+n, n);
		star(x+2*n, y+2*n, n);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	star(0,0,n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << (s[i][j]=='*'?'*':' ');
		}
		cout << "\n";
	}
	return 0;
}