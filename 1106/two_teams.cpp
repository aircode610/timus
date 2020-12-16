#include <bits/stdc++.h>

using namespace std;

const int M = 100 + 10;
bool mark[M];
vector<int> g[M];
vector<int> group1;
vector<int> group2;

void dfs(int node, int par){
  for (int i = 0; i < g[node].size(); i++){
    if (mark[g[node][i]] == false && par != g[node][i]){     
      if (find(group1.begin(), group1.end(), par) == group1.end()){
	group1.push_back(g[node][i]);
      }
      else{
	group2.push_back(g[node][i]);
      }
      mark[g[node][i]] = true;
      dfs(g[node][i], g[node][i]);      
    }
  }
}

int32_t main() {

  int n; cin >> n;
  int i = 1;
  while (i <= n){
    int num; cin >> num;
    if (num == 0){
      i++;
    }
    else{
      g[i].push_back(num);
    }
  }

  fill (mark, mark+M, false);
  for (int i = 1; i <= n; i++){
    if (mark[i] == false){
      group1.push_back(i);
      mark[i] = true;
      dfs(i, i);
    }
  }

  cout << group1.size() << endl;
  for (int i = 0; i < group1.size(); i++){
    cout << group1[i] << " ";
  }
  cout << endl;
  
  return 0;
}
