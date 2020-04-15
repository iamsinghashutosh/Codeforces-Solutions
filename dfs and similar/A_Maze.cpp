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

int n,m,k;
map<pii,vector<pii> > v;
map<pii,int> vis;
vector<string> vs;

void dfs(pii p)
{
    if(k==0)
        return;
    vis[p]=1;
    for(pii i:v[p])
    {
        if(vis[i])
            continue;
        dfs(i);
        if(k==0)
            return;
    }
    vs[p.F][p.S]='X';
    k--;
}


void solve()
{ 
  cin >> n >> m >> k;
  f(i,n)
  {
      string s;
      cin >> s;
      vs.pb(s);
  }
  int p1=-1,p2=-1;
  f(i,n)
  {
      f(j,m)
      {
          if(vs[i][j]=='.')
          {
              p1=i;
              p2=j;
              if(i<(n-1) && vs[i+1][j]=='.')
              {
                  v[{i,j}].pb({i+1,j});
                  v[{i+1,j}].pb({i,j});
              }
              if(i>0 && vs[i-1][j]=='.')
              {
                  v[{i,j}].pb({i-1,j});
                  v[{i-1,j}].pb({i,j});                  
              }
              if(j<(n-1) && vs[i][j+1]=='.')
              {
                  v[{i,j}].pb({i,j+1});
                  v[{i,j+1}].pb({i,j});
              }
              if(j>0 && vs[i][j-1]=='.')
              {
                  v[{i,j}].pb({i,j-1});
                  v[{i,j-1}].pb({i,j});   
              }
          }
      }
  }
  dfs({p1,p2});
  f(i,n)
    cout << vs[i] << '\n';
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
