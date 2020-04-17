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
#define F first
#define S second
#define all(a) a.begin(),a.end()
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

map<int,vector<int>> v;
vector<int> d;
map<int,int> vis;
int n;

void dfs(int x)
{
    if(d.size()==n)
        return;
    vis[x]=1;
    d.pb(x);
    int y=d.size();
    f(i,v[x].size())
    {
        if(vis[v[x][i]]==0)
        {
            dfs(v[x][i]);
        }
        if(d.size()==n)
          return;
        d.erase(d.begin()+y,d.end());
    }
}

void solve()
{ 
  cin >> n;
  int a[n];
  map<int,int> m;
  f(i,n)
  {
      cin >> a[i];
      m[a[i]]=1;
  }
  f(i,n)
  {
      if((a[i]%3)==0 && m[a[i]/3]==1)
      {v[a[i]].pb(a[i]/3);}
      if(m[a[i]*2]==1)
        {
         v[a[i]].pb(a[i]*2);   
        }
  }

  f(i,n)
  {
      d.clear();
      vis.clear();
      dfs(a[i]);
      // cout << d.size() << '\n';
      if(d.size()==n)
      {
          f(j,d.size())
          {
              cout << d[j] << " \n"[j==d.size()-1];
          }
          return;
      }
  }
 return;
}

signed main()
{
  FAST
  int T=1;
  // cin >> T;
  while(T--)
  {
    solve();
  }
  return 0;
}
