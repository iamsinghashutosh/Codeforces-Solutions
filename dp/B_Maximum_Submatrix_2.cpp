#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int         long long
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
  int n,m;
  cin >>n >> m;
  int dp[n][m];
  mems(dp);
  f(i,n)
  {
      string s;
      cin >> s;
     fr(j,m-1,0)
      {
        if(j==m-1 || s[j]=='0')
          dp[i][j]=s[j]-'0';
        else
          dp[i][j]=dp[i][j+1]+1;
      }
  }
  int ans=0;
  f(j,m)
  {
      vi tmp;
      f(i,n)
      {
          tmp.pb(dp[i][j]);
      }
      sort(all(tmp));
      f(i,n)
      {
         ans=max(ans,tmp[i]*(n-i));
      }
  }
  cout << ans << '\n';
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
