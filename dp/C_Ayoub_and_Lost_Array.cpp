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
#define sz(x) (int)(x).size()
#define lb lower_bound
#define ub upper_bound
#define all(a) a.begin(),a.end()
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

void solve()
{
  int n,l,r;
  cin >> n >> l >> r;
  int r1=0,r2=0,r0=0;
  r1=(r+1)/3;r1-=(l)/3;
  r2=(r+2)/3,r2-=(l+1)/3;
  r0=r/3,r0-=(l-1)/3;
  int dp[n+1][3];
  dp[0][0]=r0;
  dp[0][1]=r1;
  dp[0][2]=r2;
  fp(i,1,n)
  {
    dp[i][0]=(dp[i-1][1]%mod * r2%mod)%mod + (dp[i-1][2]%mod * r1%mod)%mod + (dp[i-1][0]%mod * r0%mod)%mod;
    dp[i][0]%=mod;
    dp[i][1]=(dp[i-1][1]%mod * r0%mod)%mod + (dp[i-1][2]%mod * r2%mod)%mod + (dp[i-1][0]%mod * r1%mod)%mod;
    dp[i][1]%=mod;
    dp[i][2]=(dp[i-1][1]%mod * r1%mod)%mod + (dp[i-1][2]%mod * r0%mod)%mod + (dp[i-1][0]%mod * r2%mod)%mod;
    dp[i][2]%=mod;
  } 
   cout << dp[n-1][0] << '\n';
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