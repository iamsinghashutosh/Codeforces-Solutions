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

/*
First we would check if any back-edge is already present in
the graph with directed edges.If so ,then there must exist a
cycle already which can't be modified since we can't change
directed edges.
If there isn't any cycle present in the graph, then we can 
assign all undirected edges from the vertices having directed edges  
the direction starting from the vertices having directed edges.
This will ensure that there would be no back-edges in the graph leading
to cycle.
No this can't ensure  that there is no back-edge.Topological Sort is 
required for that.
*/

vector<vi> v;
vi col;
vi tp;

void dfs(int x)
{
    col[x]=1;
    for(auto u:v[x])    
        if(!col[u])
            dfs(u);
    tp.pb(x);
}

void solve()
{
  int n,m;
  cin >> n >> m;
  vii u;
  tp.clear();
  col=vi(n+1);
    v=vector<vi>(n+1);
  f(i,m)
  {
      int t,x,y;
      cin >> t >> x >> y;
      if(t==1)
      {
          v[x].pb(y);
      }
      u.pb({x,y});
  }
  fp(i,1,n)
  {
      if(col[i]==0)
        dfs(i);
  }
  reverse(all(tp));
  map<int,int> mp;
  f(i,sz(tp))
   mp[tp[i]]=i;
  fp(i,1,n)
  {
      for(auto x:v[i])
      {
          if(mp[x]>mp[i])
            continue;
          else
          {
              cout << "NO\n";return;
          }
      }
  }
  cout << "YES\n";
    for(auto x:u)
    {
        if(mp[x.F]<mp[x.S])
        cout << x.F <<  " " << x.S << '\n';
        else
        cout << x.S << " " << x.F << '\n';
    }
  return;
} 

signed main()
{
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  FAST
  int T=1;
  cin >> T;
  while(T--)
  {
    solve();
  }
  return 0;
}
