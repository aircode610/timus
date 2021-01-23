#include <bits/stdc++.h>

using namespace std;
const int M = 500+10, INF=1e9;
int n,k, dp[M][M], sum[M], horses[M];

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++){
    cin >> horses[i];
    sum[i] = sum[i-1] + horses[i];
  }
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= k; j++){
      dp[i][j] = INF;
      for (int len = 1; len <= i; len++){
	int w = sum[i]-sum[i-len];
	if (i-len > 0 && j-1 == 0)
	  continue;
	dp[i][j] = min(dp[i-len][j-1]+(w*(len-w)), dp[i][j]);
      }
    }
  }
  cout << dp[n][k] << endl;
  return 0;
}
