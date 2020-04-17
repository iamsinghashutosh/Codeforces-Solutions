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
#define pii pair<int,int>
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

map<pii,int> mark;
vector<int> v[150001],pv[150001];
int vis[150001];
int flg=1;

void dfs(int x)
{
    vis[x]=1;
    f(i,v[x].size())
    {
        if(vis[v[x][i]]==0)
        {
            
               f(j,v[x].size())
                {
                    if(v[x][j]!=v[x][i] && mark[{v[x][j],v[x][i]}]==0)
                    {
                        flg=0;return;
                    }
                }
            
            dfs(v[x][i]);
        }
    }
}

void solve()
{ 
  int n,m;
  cin >> n >> m;
  f(i,m)
  {
      int x,y;
      cin >> x>>y;
      v[x].pb(y);
      v[y].pb(x);
      mark[{x,y}]=1;
      mark[{y,x}]=1; 
  }
  fp(i,1,n)
  {
      if(vis[i]==0)
      {
          dfs(i);
        //   cout << i << '\n';
          if(flg==0)
            {cout <<"NO\n";return;}
      }
  }
  cout << "YES\n";
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