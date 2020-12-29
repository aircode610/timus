#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=2e6+10,INF=3e6;
vector<pair<int,int> >off;
int n,m,dp[M];
int32_t main()
{
  cin>>n;
  for(int i=0;i<n;i++)
    {
      int p;cin>>p;
      off.push_back({(1<<i),p});
    }
  cin>>m;
  for(int i=0;i<m;i++)
    {
      int p;cin>>p;
      int k;cin>>k;
      int mask=0;
      for(int j=0;j<k;j++)
	{
	  int ind;cin>>ind;
	  ind--;
	  mask|=(1<<ind);
	}
      off.push_back({mask,p});
    }
  fill(dp+1,dp+M,INF);
  for(int mask=1;mask<(1<<20);mask++)
    for(int i=0;i<off.size();i++)
      {
	int submask=(off[i].first & mask);
	int p=off[i].second;
	if(submask)
	  dp[mask]=min(dp[mask],p+dp[mask^submask]);
      }
  int k;cin>>k;
  int maskans=0;
  for(int i=0;i<k;i++)
    {
      int ind;cin>>ind;
      ind--;
      maskans|=(1<<ind);
    }
  cout<<dp[maskans]<<endl;
  return 0;
}
