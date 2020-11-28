#include <bits/stdc++.h>

using namespace std;

const int M = 100 + 10;
int dp[M][M];

int main() {

  int N;
  cin >> N;

  int square[N][N];
  
  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      cin >> square[i][j];
    }
  }

  for (int i = 1; i <= N; i++){
    for (int j = 1; j <= N; j++){
      dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + square[i-1][j-1];
    }
  }

  int ans = -127;
  
  for(int i1=1;i1<=N;i1++){
    for(int j1=1;j1<=N;j1++){
      for(int i2=1;i2<=i1;i2++){
	for(int j2=1;j2<=j1;j2++){
	  ans=max(dp[i1][j1]-dp[i2-1][j1]-dp[i1][j2-1]+dp[i2-1][j2-1],ans);
	}
      }
    }
  }       

  cout << ans << endl;
  
  return 0;
  
}
