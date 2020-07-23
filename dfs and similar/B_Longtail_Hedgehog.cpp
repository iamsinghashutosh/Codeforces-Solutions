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

int n,m;
vector<vi> v;
vi vis;
int d[200005];

void dfs(int x)
{
    vis[x]=1;
    for(auto u:v[x])
    {
        if(u<x)
        {
          if(!vis[u])
          {
             dfs(u);
          }
          d[x]=max(d[x],d[u]+1);
        }
    } 
}

void solve()
{
  cin >>n >> m;
  v=vector<vi>(n+1);
  vis=vi(n+1);
  f(i,m)
    {
        int x,y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
  fp(i,1,n)
    d[i]=1;
  fp(i,1,n)
  {
      if(!vis[i])
        dfs(i);
  }
  int ans=0;
  fp(i,1,n)
  {
      ans=max(sz(v[i])*d[i],ans);
  }
  cout << ans << '\n';
  return;
} 

signed main()
{
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  FAST
  int T=1;
  // cin >> T;
  while(T--)
  {
    solve();
  }
  return 0;
}
