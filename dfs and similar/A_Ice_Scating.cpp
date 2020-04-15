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
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

int n,x[1001],y[1001],vis[1001];

void dfs(int u)
{
    vis[u]=1;
    fp(i,1,n)
    {
        if(vis[i]==0)
        {
            if(x[i]==x[u] || y[i]==y[u])
                dfs(i);
        }
    }
}

void solve()
{ 
  cin >> n;
  fp(i,1,n)
    cin >> x[i] >> y[i];
  int ans=0;
  fp(i,1,n)
  {
      if(vis[i]==0)
        {
            ans++;
            dfs(i);
        }
  }
  cout << ans-1 << '\n';
 return;`
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
