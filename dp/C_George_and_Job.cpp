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

void solve()
{
  int n,m,k;
  cin >> n>> m >> k;
  int p[n+1],pre[n+1];
  pre[0]=0;
  fp(i,1,n)
  {
      cin >> p[i];
      pre[i]=p[i]+pre[i-1];
  }
  int dp[k+1][n+1];
  memset(dp,0,sizeof(dp));
  fp(i,1,k)
  {
      fp(j,1,n)
      {
          if((i*m)>j)
            dp[i][j]=0;
          else
                dp[i][j]=max(dp[i][j-1],dp[i-1][j-m]+pre[j]-pre[j-m]);
      }
  }
  cout << dp[k][n] << '\n';
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
