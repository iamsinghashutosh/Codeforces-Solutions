#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int         long long
#define mod         1000000007
#define FAST        ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define f(i,n)      for(int i=0;i<n;i++)
#define fp(i,k,n)   for(int i=k;i<=n;i++)
#define fr(i,k,n)   for(int i=k;i>=n;i--)
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define dbg(x)      cout << (#x) << " is " << (x) << '\n' 
#define F           first
#define S           second
#define sz(x)       (int)(x).size()
#define lb          lower_bound
#define ub          upper_bound
#define mems(x)     memset(x,0,sizeof(x))
#define all(a)      a.begin(),a.end()
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
/*---------------------------------------------------------------------------------------------------*/
const int MX=2e5+5;
int a[MX];
int n;
vi v[MX];
int res[MX],dp[MX];
void dfs1(int x,int pa)    // x as root
{
    dp[x]=a[x];
    for(auto u:v[x])
    {
        if(u==pa)
            continue;
        dfs1(u,x);
        dp[x]+=max(0ll,dp[u]);  
    }
}

void dfs2(int x,int pa)   // re-rooting its children
{
    res[x]=dp[x];
    for(auto u:v[x])
    {
        if(u==pa)
            continue;
        dp[x]-=max(dp[u],0ll);
        dp[u]+=max(0ll,dp[x]);
        dfs2(u,x);
        dp[u]-=max(0ll,dp[x]);
        dp[x]+=max(0ll,dp[u]);
    }
}
void solve()
{
  cin >> n;
  f(i,n)
    {
        cin >> a[i+1];
        if(a[i+1]==0)
            a[i+1]=-1;
    }

  f(i,n-1)
  {
      int x,y;
      cin >> x >>y;
      v[x].pb(y);
      v[y].pb(x); 
  }
  dfs1(1,-1);
  dfs2(1,-1);
  fp(i,1,n)
    cout << res[i] << ' ';
  cout << '\n';
  return;
} 

signed main()
{
  FAST
  int T=1;
//   cin >> T;
  while(T--)
  {
    solve();
  }
  return 0;
}
