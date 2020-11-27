#include <bits/stdc++.h> 

using namespace std;

double dp[1005][1005];
bool mark[1005][1005];

int main() {

  int N,M;
  cin >> N >> M;

  vector<pair<int, int> > quarters;
  int K;
  cin >> K;

  for (int i = 0; i < K; i++){
    int x, y;
    cin >> x >> y;
    mark[x][y] = true;
  }

  for (int i = 1; i < 1005; i++){
    dp[N + 2][i] = dp[i][M+2] = 1000000;
  }

  dp[N+2][M+1] = -100;
  
  for (int i = N + 1; i >= 1; i--){
    for (int j = M + 1; j >= 1; j--){
      dp[i][j] = min(dp[i + 1][j] + 100, dp[i][j+ 1] + 100);
      if (mark[i][j]){
	dp[i][j] = min(dp[i][j], dp[i + 1][j + 1] + 141.421356237);
      }
    }
  }
 
  cout<<fixed<<setprecision(0)<<dp[1][1]<<endl;
  
  return 0;
  
}
