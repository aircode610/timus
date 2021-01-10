#include <bits/stdc++.h>

using namespace std;

int dp[10][82];

int main() {

  int S; cin >> S;
  
  for (int i = 0; i <= 9; i++){
    dp[1][i] = 1;
    if (i != 0)
      dp[i][0] = 1;
  }
  for (int i = 1; i <= 9; i++){
    for (int j = 1; j <= 81; j++){
      for (int k = 0; k <= 9; k++){
	if (j >= k)
	  dp[i][j] += dp[i-1][j-k];
      }
    }
  }
  
  cout << dp[9][S] + (S==1) << endl;
  
  return 0;
}
