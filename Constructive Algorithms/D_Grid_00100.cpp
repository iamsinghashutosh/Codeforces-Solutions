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
#define mems(a)     memset(a,0,sizeof((a)))
#define all(a)      a.begin(),a.end()
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
/*---------------------------------------------------------------------------------------------------*/

void solve()
{
  int n,k;
  cin >> n >> k;
  int a[n][n];
  mems(a);
  int r=0,rnd=0;
  f(i,k)
  {
     int val=(i+rnd)%n;
     a[r][val]=1;
     r++;
     if(r==n)
     {
         r=0;
         rnd++;
     }
  }
  int r1=mod,r2=0;
  int c1=mod,c2=0;
  f(i,n)
   {
     int cnt=0;
       f(j,n)
        {
            cnt+=a[i][j];
        }
      r1=min(cnt,r1);
      r2=max(cnt,r2);
   }
   f(j,n)
   {
       int cnt=0;
       f(i,n)
        cnt+=a[i][j];
      c1=min(cnt,c1);
      c2=max(c2,cnt);
   }
   int ans=(r2-r1)*(r2-r1) + (c2-c1)*(c2-c1);
   cout << ans << '\n';
  f(i,n)
   {f(j,n)
    cout << a[i][j];
   cout << '\n';}

   
  return;
} 

signed main()
{
  FAST
  int T=1;
  cin >> T;
  while(T--)
  {
    solve();
  }
  return 0;
}
