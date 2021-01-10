#include <bits/stdc++.h>
using namespace std;

map<string, vector<string> > g;
deque<string> saf;
map<string, int> dis;

void bfs(string v){
  saf.push_back(v);
  dis[v] = 0;
  while (saf.size()){
    string u = saf[0];
    saf.pop_front();
    for (auto c:g[u]){
      if (dis[c] == -1){
	saf.push_back(c);
	dis[c] = dis[u] + 1;
      }
    }
  }
}

int main() {

  int n; cin >> n;
  for (int i = 1; i <= n; i++){
    string a, b, c;
    cin >> a >> b >> c;
    g[a].push_back(b);
    g[a].push_back(c);
    g[b].push_back(a);
    g[b].push_back(c);
    g[c].push_back(a);
    g[c].push_back(b);
    dis[a] = -1;
    dis[b] = -1;
    dis[c] = -1;
  }

  if (dis.find("Isenbaev") != dis.end())
    bfs("Isenbaev");

  while (dis.size() != 0){
    auto p = *dis.begin();
    if (p.second == -1)
      cout << p.first << " undefined" << endl;
    else
      cout << p.first << " " << p.second << endl;
    dis.erase(p.first);
  }
  
  return 0;
}
