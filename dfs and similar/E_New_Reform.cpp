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

vector<int> v[100005];
int vis[100005];
int cnt=0;

void dfs(int x,int pa)
{
    vis[x]=1;
    for(auto u:v[x])
    {
        if(vis[u])
        {
            if(u!=pa)
                cnt++;
        }
        else
            dfs(u,x);
    }
}

void solve()
{ 
  int n,m;
  cin >> n >> m;
  f(i,m)
  {
    int x,y;
    cin >> x >> y;
    v[x].pb(y);
    v[y].pb(x);      
  }
  int ans=0;
  fp(i,1,n)
  {
      if(!vis[i])
      {
         cnt=0;
        dfs(i,i);
        if(cnt==0)
            ans++;
      }
  }
  cout << ans << '\n';
  return;
}

signed main()
{
  FAST
  int T=1;
//    cin >> T;
  while(T--)
  {
    solve();
  }
  return 0;
}