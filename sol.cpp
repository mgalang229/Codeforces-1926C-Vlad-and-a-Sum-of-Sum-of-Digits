#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxN = 2e5 + 1;
int dp[maxN];

int get_sum(int x) {
	int res = 0;
	while (x > 0) {
		if (dp[x] > 0) {
			res += dp[x];
			break;
		}
		res += x % 10;
		x /= 10;
	}
	return res;
}

void test_case(int& tc) {
	int n;
	cin >> n;
	cout << dp[n] << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	memset(dp, 0, sizeof(dp));
	for (int i = 1; i < maxN; i++) {
		dp[i] = get_sum(i);
	}
	for (int i = 1; i < maxN; i++) {
		dp[i] += dp[i-1];
	}
	
	int T = 1;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		test_case(tc);
	}
}
