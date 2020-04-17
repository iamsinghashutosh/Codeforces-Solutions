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

vector<int> node[105],l[105];
int n,m;
int visited[105];
void dfs(int x)
{
    visited[x]=1;
    f(i,node[x].size())
    {
        f(j,l[node[x][i]].size())
        {
            if(visited[l[node[x][i]][j]]==0)
                dfs(l[node[x][i]][j]);
        }
    }
}
void solve()
{ 
  cin >> n >> m;
  int cnt=0,flg=0;
  f(i,n)
  {
      int k;
      cin >> k;
      if(k==0)
        flg++;
      else
      while(k--)
      {
          int x;
          cin >> x;
          l[i+1].pb(x);
          node[x].pb(i+1);
      }
  }
  fp(i,1,n)
  {
      if(visited[i]==0 && node[i].size()!=0)
      {
          dfs(i);
          cnt++;
      }
  }
  if(flg!=n)
    cnt--;
  cout << cnt+flg << '\n';
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