#include <iostream>
#include <cstring>

using namespace std;

int a[1001][1001];

int main() {
	char A[1001], B[1001];
	cin >> A >> B;
	for (int i = 0; i < strlen(A); i++) {
		for (int j = 0; j < strlen(B); j++) {
			if (A[i] == B[j]) a[i + 1][j + 1] = a[i][j] + 1;
			else a[i + 1][j + 1] = (a[i + 1][j] > a[i][j + 1] ? a[i + 1][j] : a[i][j + 1]);
		}
	}
	cout << a[strlen(A)][strlen(B)];
	return 0;
}