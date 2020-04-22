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
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define f(i,n) for(int i=0;i<n;i++)
#define fp(i,k,n) for(int i=k;i<=n;i++)
#define fr(i,k,n) for(int i=k;i>=n;i--)
#define pb push_back
#define pii pair<int,int>
#define dbg(x) cout << (#x) << " is " << (x) << '\n' 
#define F first
#define S second
#define all(a) a.begin(),a.end()
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

vector<vector<int>> v;
int vis[200005];

void bfs(int x,vector<int> &d)
{
    vis[x]=1;
    d[x]=0;
    queue<int> q;
    q.push(x);
    while(!q.empty())
    {
        int p=q.front();
        q.pop();
        for(auto u:v[p])
        {
            if(!vis[u])
            {
                d[u]=d[p]+1;
                q.push(u);
                vis[u]=1;
            }
        }
    }
}

void solve()
{ 
  int n,m,a,b,c;
  cin >> n >> m >> a >> b >> c;
  int p[m+1];
  p[0]=0;
  fp(i,1,m)
    cin >> p[i];
  sort(p,p+m+1);
   fp(i,1,m)  
    p[i]+=p[i-1];
  v=vector<vector<int>>(n+1); // better way to clear the vector
  f(i,m)
  {
      int x,y;
      cin >> x >> y;
      v[x].pb(y);
      v[y].pb(x);
  }
  memset(vis,0,sizeof vis);
  vector<int> da(n+1,mod),db(n+1,mod),dc(n+1,mod);
  bfs(a,da);
  memset(vis,0,sizeof vis);
  bfs(b,db);
  memset(vis,0,sizeof vis);
  bfs(c,dc);
  int ans=n*mod;
  fp(x,1,n)
  {
      if((db[x]+da[x]+dc[x])>m)
        continue;
      ans=min(ans,p[db[x]]+p[db[x]+da[x]+dc[x]]);
  }
  cout << ans << '\n';
  return;
}

signed main()
{
  FAST
  int T=1;
   cin >> T;
  while(T--)
  {
    solve();
  }
  return 0;
}