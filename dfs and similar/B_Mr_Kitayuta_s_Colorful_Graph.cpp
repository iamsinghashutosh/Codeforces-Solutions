/*
 Ashutosh Singh
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
#define F first
#define S second
#define all(a) a.begin(),a.end()
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

vector<pair<int,int>> v[101]; 
int visited[101];

bool dfs(int l,int r,int col)
{
    visited[l]=1;
    if(l==r)
        return 1;
    f(i,v[l].size())
    {
        if(!visited[v[l][i].F] && v[l][i].S==col)
            {
                    if(dfs(v[l][i].F,r,col))
                        return true;
            }
    }
    return false;
} 

void solve()
{
  int n,m;
  cin >> n >> m;
  f(i,m)
  { 
      int x,y,col;
      cin >> x >> y>>col;
      v[x].pb({y,col});
      v[y].pb({x,col});
  }
  int q;
  cin >> q;
  while(q--)
  {
      int l,r;
      cin >> l>> r;
      int ans=0;
      fp(i,1,m)
        {
            memset(visited,0,sizeof(visited));
            ans+=dfs(l,r,i);
        }
     cout << ans << '\n';
  }
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
