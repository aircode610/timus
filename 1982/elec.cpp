#include <bits/stdc++.h>

using namespace std;

const int M = 100 + 10, INF = 1e9;

int ans, n, k, stations[M], c[M][M], wp[M];
set<pair<int, int> > s;
bool mark[M];

void prim(int r){
  fill(wp, wp+M, INF);
  wp[r] = 0;
  s.insert({0, r});
  while (s.size()){
    int v = (*s.begin()).second;
    ans += (*s.begin()).first;
    mark[v] = true;
    s.erase(*s.begin());
    for (int i = 1; i <= n; i++){
      int w = c[v][i];
      if (!mark[i]){
	s.erase({wp[i], i});
	if (wp[i] > w)
	  wp[i] = w;
	s.insert({wp[i], i});
      }
    }
  }
}

int main(){
  cin >> n >> k;
  int station = 1;
  for (int i = 1; i <= k; i++){
    int s; cin >> s;
    stations[s] = true;
    station = s;
  }
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= n; j++){
      int d; cin >> d;
      if (stations[i] == stations[j] && stations[i] == true)
	c[i][j] = 0;
      else
	c[i][j] = d;
    }
  }
  prim(station);
  cout << ans << endl;
  return 0;
}
