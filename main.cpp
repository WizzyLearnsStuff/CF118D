#include<iostream>

using namespace std;


static long long dp[101][101][11][11];
#define M 100000000

int main() {
	long long n1, n2, k1, k2;
	cin >> n1 >> n2 >> k1 >> k2;

	for (int f = 0; f <= n1; f++)
	for (int h = 0; h <= n2; h++)
	for (int kf = 0; kf <= k1; kf++)
	for (int kh = 0; kh <= k2; kh++) {
		long long ans = 0;	
		if (kf > 0 && f > 0) ans = (ans + dp[f - 1][h][kf - 1][k2]) % M;
		if (kh > 0 && h > 0) ans = (ans + dp[f][h - 1][k1][kh - 1]) % M;
		if (f == 0 && h == 0) ans = 1;
		dp[f][h][kf][kh] = ans;
		// std::cout << ans << ' ' << kf << ' ' << kh << ' ' << f << ' ' << ' ' << h << '\n';
	}

	cout << dp[n1][n2][k1][k2];
}
