#include <bits/stdc++.h>

using namespace std;

const int M = 200+10, INF = 1e9;

pair<double, double> stations[M];
vector<pair<int, double> > g[M];
vector<pair<int, int> > connections;
double fs, us;
int n;
set<pair<double, int> > s;
double dis[M];
int par[M];
bool mark[M];
deque<int> ans;

void dijkstra(int r){
  fill(dis, dis+M, INF);
  dis[r] = 0;
  s.insert({dis[r], r});
  while (s.size()){
    int v = (*s.begin()).second;
    s.erase(*s.begin());
    mark[v] = true;
    for (auto p:g[v]){
      int u = p.first;
      double w = p.second;
      if (!mark[u]){
	s.erase({dis[u], u});
	if (dis[v] + w < dis[u]){
	  par[u] = v;
	  dis[u] = dis[v] + w;
	}
	s.insert({dis[u], u});
      }
    }
  }
}

int main() {

  cin >> fs >> us;
  cin >> n;
  for (int i = 1; i <= n; i++){
    double x, y;
    cin >> x >> y;
    stations[i] = {x, y};
  }
  int s1, s2;
  while (true){
    cin >> s1 >> s2;
    if (s1 == 0 && s2 == 0)
      break;
    connections.push_back({s1, s2});
    connections.push_back({s2, s1});
  }
  double x, y;
  cin >> x >> y;
  pair<double, double> from = {x, y};
  cin >> x >> y;
  pair<double, double> to = {x, y};

  for (int i = 0; i <= n; i++){
    double w = 0.0;
    if (i == 0){
      if (from.first == to.first && from.second == to.second)
	w = 0.0;
      else if (from.first == to.first)
	w = (abs(from.second - to.second) + 0.0) / fs;
      else if (from.second == to.second)
	w = (abs(from.first - to.first) + 0.0) / fs;
      else
	w = sqrt(pow(abs(from.first - to.first),2)+pow(abs(from.second - to.second),2)) / fs + 0.0;
      g[0].push_back({n+1, w});
      g[n+1].push_back({0, w});
      continue;
    }
    if (from.first == stations[i].first && from.second == stations[i].second)
      w = 0.0;
    else if (from.first == stations[i].first)
      w = (abs(from.second - stations[i].second) + 0.0) / fs + 0.0;
    else if (from.second == stations[i].second)
      w = (abs(from.first - stations[i].first) + 0.0) / fs + 0.0;
    else
	w = sqrt(pow(abs(from.first - stations[i].first),2)+pow(abs(from.second - stations[i].second),2)) / fs + 0.0;
    g[0].push_back({i, w});
    g[i].push_back({0, w});
    if (to.first == stations[i].first && to.second == stations[i].second)
      w = 0.0;
    else if (to.first == stations[i].first)
      w = (abs(to.second - stations[i].second) + 0.0) / fs + 0.0;
    else if (to.second == stations[i].second)
      w = (abs(to.first - stations[i].first) + 0.0) / fs + 0.0;
    else
	w = sqrt(pow(abs(to.first - stations[i].first),2)+pow(abs(to.second - stations[i].second),2)) / fs + 0.0;
    g[n+1].push_back({i, w});
    g[i].push_back({n+1, w});
  }
  for (int i = 0; i < connections.size(); i++){
    double w = 0.0;
    pair<double, double> s1 = stations[connections[i].first];
    pair<double, double> s2 = stations[connections[i].second];
    if (s1.first == s2.first && s1.second == s2.second)
      w = 0.0;
    else if (s1.first == s2.first)
      w = (abs(s1.second - s2.second) + 0.0) / us + 0.0;
    else if (s1.second == s2.second)
      w = (abs(s1.first - s2.first) + 0.0) / us + 0.0;
    else
	w = sqrt(pow(abs(s1.first - s2.first),2)+pow(abs(s1.second - s2.second),2)) / us + 0.0;
    g[connections[i].first].push_back({connections[i].second, w});
  }
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= n; j++){
      pair<double, double> s1 = stations[i];
      pair<double, double> s2 = stations[j];
      double w = 0.0;
      if (s1.first == s2.first && s1.second == s2.second)
	w = 0.0;
      else if (s1.first == s2.first)
	w = (abs(s1.second - s2.second) + 0.0) / fs + 0.0;
      else if (s1.second == s2.second)
	w = (abs(s1.first - s2.first) + 0.0) / fs + 0.0;
      else
	w = sqrt(pow(abs(s1.first - s2.first),2)+pow(abs(s1.second - s2.second),2)) / fs + 0.0;
      /*bool con = true;
      for (int k = 0; k < g[i].size(); k++){
	if (g[i][k].first == j){
	  con = false;
	  break;
	}
      }
      if (con == true)*/
      g[i].push_back({j, w});
    }
  }
  dijkstra(0);
  /*
  cout << "______________________" << endl;
  for (int i = 0; i <= n+1; i++){
    for (int j = 0; j < g[i].size(); j++){
      cout.precision(10);
      cout << i << " -> " << g[i][j].first <<  " w: " << g[i][j].second << endl;
    }
  }
  cout << "______________________" << endl;
  */
  cout << fixed;
  cout << setprecision(7) << dis[n+1] << endl;
  int s = n+1;
  while (true){
    s = par[s];
    if (s == 0)
      break;
    ans.push_front(s);
  }
  cout << ans.size() << ' ';
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << ' ';
  cout << endl;
}
