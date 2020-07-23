#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
// #define int         long long
#define mod         1000000007
#define FAST        ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define f(i,n)      for(int i=0;i<n;i++)
#define fp(i,k,n)   for(int i=k;i<=n;i++)
#define fr(i,k,n)   for(int i=k;i>=n;i--)
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define dbg(x)      cout << (#x) << " is " << (x) << '\n' 
#define F           first
#define S           second
#define sz(x)       (int)(x).size()
#define lb          lower_bound
#define ub          upper_bound
#define mems(x)     memset(x,0,sizeof(x))
#define all(a)      a.begin(),a.end()
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

/*---------------------------------------------------------------------------------------------------*/

void solve()
{
  int n;
  cin >> n;
  int x;
  cin>>x;
  vi v;
  v.pb(x);
  f(i,n-1)
   {
     cin >>x;
     if(v.back()!=x)
      v.pb(x);
   }
   n=sz(v);
   int dp[n+2][n+2][2];
   fp(i,0,n+1)
    fp(j,0,n+1)
     fp(k,0,1)
      {
      if(i==j)
        dp[i][j][k]=0;
      else
        dp[i][j][k]=mod;
      }
    fp(len,1,n)
    {
      fp(l,1,n-len+1)
      {
        int r=l+len-1;
        dp[l][r][0]=min(dp[l][r][0],dp[l+1][r][1]+(int)(v[l-1]!=v[r-1]));
        dp[l][r][0]=min(dp[l][r][0],dp[l+1][r][0]+1);
        dp[l][r][1]=min(dp[l][r][1],dp[l][r-1][1]+1);
        dp[l][r][1]=min(dp[l][r][1],dp[l][r-1][0]+(int)(v[l-1]!=v[r-1]));
      }
    }
    cout << min(dp[1][n][0],dp[1][n][1]) << '\n';
  return;
} 

signed main()
{
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  FAST
  int T=1;
  // cin >> T;
  while(T--)
  {
    solve();
  }
  return 0;
}