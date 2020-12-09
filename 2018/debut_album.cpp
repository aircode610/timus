#include <bits/stdc++.h>
#define int long long

using namespace std;

int dp[50000][2];
const int mod = 1e9+7;

int32_t main() {

  int n, a, b;
  cin >> n >> a >> b;

  dp[0][1] = 1;
  dp[0][2] = 1;
  
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= a && j <= i; j++){
      (dp[i][1] += dp[i-j][2])%=mod;
    }
    for (int j = 1; j <= b && j <= i; j++){
      (dp[i][2] += dp[i-j][1])%=mod;
    }
  }

  cout << (dp[n][1] + dp[n][2])%mod << endl;
  
  return 0;
  
}
