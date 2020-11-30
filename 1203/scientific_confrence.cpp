#include <bits/stdc++.h>

using namespace std;

const int M = 30000 + 10;
int dp[M];
int periods[M];

int32_t main() {  
  
  int N;
  cin >> N;  
  
  for (int i = 1; i <= N; i++){
    int start, end;
    scanf("%d%d",&start,&end);
    
    periods[end] = max(periods[end], start);
  }

  for (int t = 1; t <= 30000; t++){
    if (periods[t] != 0)
      dp[t] = max(dp[t-1], dp[periods[t] - 1] + 1);
    else
      dp[t] = dp[t-1];
  }

  cout << dp[30000] << endl;
  
  return 0;
  
}
