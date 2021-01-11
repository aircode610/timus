#include <bits/stdc++.h>
#define int long long

using namespace std;

const int M = 55+10;
int dp[M];

int32_t main() {
  int N; cin >> N;

  dp[1] = 1;
  dp[2] = 1;
  dp[3] = 2;
  for (int i = 4; i <= N; i++){
    dp[i] = dp[i-3] + dp[i-1] + 1;
  }

  cout << dp[N] << endl;
}
