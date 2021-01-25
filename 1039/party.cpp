#include <bits/stdc++.h>

using namespace std;

const int M = 6e3+10;
int dp[M][2], c[M], n;
vector<int> g[M];
bool mark[M];

void dfs(int v){
  mark[v] = true;
  if (c[v] > 0)
    dp[v][1] = c[v];
  for (auto u:g[v]){
    if (!mark[u]){
      dfs(u);
      dp[v][0] += max(dp[u][1], dp[u][0]);
      dp[v][1] += dp[u][0];
    }
  }
}

int32_t main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> c[i];
  int u=1, v=1;
  while (u != 0 && v != 0){
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1);
  cout << max(dp[1][0], dp[1][1]) << endl;
  return 0;
}
