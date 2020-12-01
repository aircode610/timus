#include <bits/stdc++.h>

using namespace std;

const int M = 30;
int dp[M][2];

int main() {
  int n, k;
  cin >> n;
  cin >> k;

  dp[0][0] = 1;
  dp[0][1] = 0;
  for (int i = 1; i <= n; i++){
    dp[i][0] = dp[i-1][1];
    dp[i][1] = (k-1)*(dp[i-1][0]+dp[i-1][1]);
  }

  cout << dp[n][0] + dp[n][1] << endl;
  
  return 0;
}
