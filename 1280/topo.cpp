#include <bits/stdc++.h>

using namespace std;

const int M = 1000+10;

vector<int> g[M], plan;
int in[M];

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++){
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    in[v]++;
  }
  for (int i = 1; i <= n; i++){
    int p; cin >> p;
    plan.push_back(p);
  }
  for (int i = 0; i < n; i++){
    if (in[plan[i]] == 0){
      for (auto u:g[plan[i]])
	in[u]--;
    }
    else {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
