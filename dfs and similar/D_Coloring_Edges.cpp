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

vector<pii> v[5005];                                                
int vis[5005],col[5005],flg=0;

void dfs(int x)
{
    vis[x]=1;
    for(auto u:v[x])
    {
        if(vis[u.F]==0)
         {
             dfs(u.F);
             col[u.S]=1;
         }
         else if(vis[u.F]==2)
         {
             col[u.S]=1;
         }
         else
         {
             col[u.S]=2;
             flg=1;
         }
    }
    vis[x]=2;
}

void solve()
{ 
  int n,m;
  cin >> n >> m;
  f(i,m)
  {
      int a,b;
      cin >> a >> b;
      v[a].pb({b,i});
  }
  fp(i,1,n)
  {
      if(vis[i]==0)
        dfs(i);
  }
  if(flg==1)
    cout << 2 << '\n';
  else 
    cout << 1 << '\n';
  f(i,m)
   cout << col[i] << " \n"[i==m-1];
  return;
}

signed main()
{
  FAST
  int T=1;
  //  cin >> T;
  while(T--)
  {
    solve();
  }
  return 0;
}