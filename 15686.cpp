#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<int> choose;
int n, m, ans=10000;

void calc() {
	int sum = 0;
	for (int i = 0; i < house.size(); i++) {
		int dis = 100;
		for (int j = 0; j < m; j++) {
			dis = min(dis, abs(house[i].first - chicken[choose[j]].first) + abs(house[i].second - chicken[choose[j]].second));
		}
		sum += dis;
	}
	ans = min(ans, sum);
}

void select(int n) {
	if (n == chicken.size()) return;
	choose.push_back(n);
	if (choose.size() == m) calc();
	select(n + 1);
	choose.pop_back();
}

int main() {
	int k;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> k;
			if (k == 1) house.push_back({ i,j });
			else if (k == 2) house.push_back({ i,j });
		}
	}
	cout << ans;
	return 0;
}