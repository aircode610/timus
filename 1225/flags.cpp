#include <bits/stdc++.h>

using namespace std;

const int M = 45+10;
long long dp[M];

int main() {

  int n;
  cin >> n;

  dp[1] = 2;
  dp[2] = 2;
  for (int i = 3; i <= n; i++){
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  cout << dp[n];

  return 0;
  
}
/*
dp[i][j] = ways of making a flag with i stripes
update: dp[i] = dp[i - 1] + dp[i - 2]
answer: sum of dp[n]
*/
