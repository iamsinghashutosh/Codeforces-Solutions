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
  cin >> n>> m;
  int dp[n+1][2]={0};
  int lft[n+1],rgt[n+1];
  int mat[n+1][m+1];
  int pos=n,flg=0;
  fr(i,n,1)
  {
      string s;
      cin >> s;
      lft[i]=m+1;
      rgt[i]=0;
      fp(j,1,m)
        {
            mat[i][j]=s[j]-'0';
            if(mat[i][j]==1)
            {
            lft[i]=min(lft[i],j);
            rgt[i]=max(rgt[i],j);
            }
        }
        if(rgt[i]>0 && !flg)
          pos=i,flg=1;
  }
  if(!flg)
    pos=1;
  dp[1][0]=2*rgt[1];
  dp[1][1]=m+1;
  fp(i,2,pos-1)
  {
      dp[i][0]=min(dp[i-1][0]+2*rgt[i],dp[i-1][1]+m+1)+1;
      dp[i][1]=min(dp[i-1][1]+2*(m+1-lft[i]),dp[i-1][0]+m+1)+1;
  }
  if(pos>1)
     dp[pos][0]=min(dp[pos-1][0]+rgt[pos],dp[pos-1][1]+m+1-lft[pos])+1;
  else
     dp[pos][0]=rgt[pos];
  cout << dp[pos][0] << '\n';
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
