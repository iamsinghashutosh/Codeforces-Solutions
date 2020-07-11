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
 int n,k;
 cin >> n >> k;
 int cnt[200005],minm=mod,mxm=0;
 mems(cnt);
 f(i,n)
    {
      int x;
      cin >> x;
      cnt[1]++;
      cnt[x+1]--;
      minm=min(minm,x);
      mxm=max(mxm,x);
    }
 fp(i,2,mxm)
  cnt[i]+=cnt[i-1];
 int ans=0,sum=0;
 fr(i,mxm,minm+1)
 {
     if(sum+cnt[i]<=k)
      sum+=cnt[i];
     else
      {
        sum=cnt[i];
        ans++;
        // if(i==minm+1 && cnt[i]!=0)
        //   ans++;
      }
 }
 if(sum>0)
  ans++;
 cout << ans << '\n';
  return ;
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
