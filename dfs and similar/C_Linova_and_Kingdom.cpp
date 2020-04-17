/*
  GOOD is not Enough
  You've got to be GREAT.
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
// #include<boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
using namespace __gnu_pbds;
using namespace std;
#define int long long
#define mod 1000000007
#define FAST ios: :sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define f(i,n) for(int i=0;i<n;i++)
#define fp(i,k,n) for(int i=k;i<=n;i++)
#define fr(i,k,n) for(int i=k;i>=n;i--)
#define pb push_back
#define F first
#define S second
#define all(a) a.begin(),a.end()
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

vector<int> v[200001];
int lvl[200001];
int rem[200001];
int d[200001];
int dfs(int u,int pa)
{
  lvl[u]=lvl[pa]+1;
  rem[u]=1;
  f(i,v[u].size())
  {
      if(v[u][i]==pa)
        continue;
      rem[u]+=dfs(v[u][i],u);
  }
  d[u]=rem[u]-lvl[u];
  return rem[u];
}

void solve()
{ 
  int n,k,ans=0;
  cin >> n >> k;
  f(i,n-1)
  {
      int x,y;
      cin >> x >>y ;
      v[y].pb(x);
      v[x].pb(y);
  }
  dfs(1,0);
  sort(d+1,d+n+1,greater<>());
	for (int i=1;i<=n-k;++i)
       ans+=d[i];
  cout << ans << '\n';
 return;
}

signed main()
{
  int T=1;
//   cin >> T;
  while(T--)
  {
    solve();
	}
  return 0;
}